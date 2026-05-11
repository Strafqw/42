import abc
import typing


class DataProcessor(abc.ABC):
    name: str

    def __init__(self) -> None:
        self.rank = 0
        self.storage: list[str] = []

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
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


if __name__ == "__main__":
    ds = DataStream()
    np = NumericProcessor()
    tp = TextProcessor()
    lp = LogProcessor()
    print("=== Code Nexus - Data Stream ===")
    print()
    print("Initialize Data Stream...")
    ds.print_processors_stats()
    print()
    print("Registering Numeric Processor")
    ds.register_processor(np)
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
    ds.process_stream(batch)
    ds.print_processors_stats()
    print()
    print("Registering other data processors")
    ds.register_processor(tp)
    ds.register_processor(lp)
    print("Send the same batch again")
    ds.process_stream(batch)
    ds.print_processors_stats()
    print()
    print(
        "Consumes some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
    )
    np.output()
    np.output()
    np.output()
    tp.output()
    tp.output()
    lp.output()
    ds.print_processors_stats()
