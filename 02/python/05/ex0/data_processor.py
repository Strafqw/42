import abc
import typing


class DataProcessor(abc.ABC):
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


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===\n")

    # Numeric Values
    print("Testing Numeric Processor...")
    np = NumericProcessor()
    print(f"Trying to validate input '42': {np.validate(42)}")
    print(f"Trying to validate input 'Hello': {np.validate("Hello")}")
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        np.ingest("foo")
    except ValueError as e:
        print(f"Got exception: {e}")
    num_data: list[int | float] = [1, 2, 3, 4, 5]
    print(f"Processing data: {num_data}")
    np.ingest(num_data)
    print("Extracting 3 values...")
    for _ in range(3):
        rank, value = np.output()
        print(f"Numeric value {rank}: {value}")

    # Text Values
    print("\nTesting Text Processor...")
    tp = TextProcessor()
    print(f"Trying to validate input '42': {tp.validate(42)}")
    txt_data = ["Hello", "Nexus", "World"]
    print(f"Processing data: {txt_data}")
    tp.ingest(txt_data)
    print("Extracting one value...")
    rank, value = tp.output()
    print(f"Text value {rank}: {value}")

    # Log Values
    print("\nTesting Log Processor...")
    lp = LogProcessor()
    print(f"Trying to validate input 'Hello': {lp.validate("Hello")}")
    log_data = [
        {"log_level": "NOTICE", "log_message": "Connection to the server"},
        {"log_level": "ERROR", "log_message": "Unauthorized access!!"}
    ]
    print(f"Processing data: {log_data}")
    lp.ingest(log_data)
    print("Extracting two values...")
    for _ in range(2):
        rank, value = lp.output()
        print(f"Log entry {rank}: {value}")
