from datetime import datetime
from pydantic import BaseModel, Field, ValidationError, model_validator
from enum import Enum


class Rank(str, Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def check_mission_rules(self):
        # Rule 1: Mission ID must start with "M"
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")
        has_leader = any(
            m.rank in (Rank.CAPTAIN, Rank.COMMANDER)
            for m in self.crew
        )
        if not has_leader:
            raise ValueError(
                "Mission must have at least one Commander or Captain")
        if self.duration_days > 365:
            experienced = sum(
                1 for m in self.crew if m.years_experience >= 5
            )
            if experienced < len(self.crew) / 2:
                raise ValueError(
                    "Long missions need 50% experienced crew (5+ years)"
                )
        if not all(m.is_active for m in self.crew):
            raise ValueError("All crew members must be active")
        return self

def main() -> None:
    print("Space Mission Crew Validation")
    print("=" * 41)

    crew = [
        CrewMember(
            member_id="CM001",
            name="Sarah Connor",
            rank=Rank.COMMANDER,
            age=45,
            specialization="Mission Command",
            years_experience=20,
        ),
        CrewMember(
            member_id="CM002",
            name="John Smith",
            rank=Rank.LIEUTENANT,
            age=38,
            specialization="Navigation",
            years_experience=12,
        ),
    ]
    mission = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date=datetime.now(),
        duration_days=900,
        crew=crew,
        budget_millions=2500.0,
    )
    print("Space Mission Crew Validation")
    print("=" * 40)
    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(crew)}")
    print
    
    # ... print mission details (Mission, ID, Destination, Duration, Budget,
    #     Crew size, then loop the crew members)
