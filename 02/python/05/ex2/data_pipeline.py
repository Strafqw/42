from abc import ABC, abstractmethod
import typing


class ExportPlugin(typing.Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class DataProcessor(ABC):
    name: str

    def __init__(self) -> None:
        self.rank = 0
        self.storage: list[str] = []

    @abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self.storage:
            raise IndexError("No data to output")
        item = self.storage.pop(0)
        rank = self.rank
        self.rank += 1
        return (rank, item)


class NumericProcessor(DataProcessor):
    name = "Numeric Processor"

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, bool):
            return False
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            return all(
                isinstance(x, (int, float)) and not isinstance(x, bool)
                for x in data
            )
        else:
            return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        items = data if isinstance(data, list) else [data]
        for x in items:
            self.storage.append(str(x))


class TextProcessor(DataProcessor):
    name = "Text Processor"

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            return all(isinstance(x, str) for x in data)
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        items = data if isinstance(data, list) else [data]
        for x in items:
            self.storage.append(x)


class LogProcessor(DataProcessor):
    name = "Log Processor"

    def validate(self, data: typing.Any) -> bool:
        def is_log_dict(d: typing.Any) -> bool:
            return (
                isinstance(d, dict)
                and "log_level" in d
                and "log_message" in d
                and isinstance(d["log_level"], str)
                and isinstance(d["log_message"], str)
            )
        if is_log_dict(data):
            return True
        if isinstance(data, list):
            return all(is_log_dict(d) for d in data)
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        items = data if isinstance(data, list) else [data]
        for d in items:
            formatted = f"{d['log_level']}: {d['log_message']}"
            self.storage.append(formatted)


class DataStream:
    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for item in stream:
            for proc in self.processors:
                if proc.validate(item):
                    proc.ingest(item)
                    break
            else:
                print(
                    "DataStream error - Can't process element in "
                    f"stream: {item}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.processors:
            print("No processor found, no data")
            return
        for proc in self.processors:
            total = proc.rank + len(proc.storage)
            remaining = len(proc.storage)
            print(
                f"{proc.name}: total {total} items processed, "
                f"remaining {remaining} on processor"
            )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self.processors:
            count = min(nb, len(proc.storage))
            batch = [proc.output() for _ in range(count)]
            plugin.process_output(batch)


class CSVExporter:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        values = [s for _, s in data]
        csv = ",".join(values)
        print("CSV Output:")
        print(csv)


class JSONExporter:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pieces = [f'"item_{rank}": "{value}"' for rank, value in data]
        body = ", ".join(pieces)
        print("JSON Output:")
        print(f"{{{body}}}")


if __name__ == "__main__":
    ds = DataStream()
    np = NumericProcessor()
    lp = LogProcessor()
    tp = TextProcessor()
    print("=== Code Nexus - Data Pipeline ===")
    print()
    print("Initialize Data Stream...")
    print()
    ds.print_processors_stats()
    print()
    print("Registering Processors")
    ds.register_processor(np)
    ds.register_processor(tp)
    ds.register_processor(lp)
    print()
    batch = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {
                'log_level': 'WARNING',
                'log_message': 'Telnet access! Use ssh instead',
            },
            {
                'log_level': 'INFO',
                'log_message': 'User wil is connected',
            },
        ],
        42,
        ['Hi', 'five'],
    ]
    print(f"Send first batch of data on stream: {batch}")
    print()
    ds.process_stream(batch)
    ds.print_processors_stats()
    print()
    print("Send 3 processed data from each processor to a CSV plugin:")
    ds.output_pipeline(3, CSVExporter())
    print()
    ds.print_processors_stats()
    print()
    batch2 = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [
            {'log_level': 'ERROR', 'log_message': '500 server crash'},
            {
                'log_level': 'NOTICE',
                'log_message': 'Certificate expires in 10 days',
            },
        ],
        [32, 42, 64, 84, 128, 168],
        'World hello',
    ]
    print(f"Send another batch of data: {batch2}")
    print()
    ds.process_stream(batch2)
    ds.print_processors_stats()
    print()
    print("Send 5 processed data from each processor to a JSON plugin:")
    ds.output_pipeline(5, JSONExporter())
    print()
    ds.print_processors_stats()
