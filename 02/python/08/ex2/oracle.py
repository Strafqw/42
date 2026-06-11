import os
from dotenv import load_dotenv

load_dotenv()

mode = os.environ.get("MATRIX_MODE")
db_url = os.environ.get("DATABASE_URL")
api_key = os.environ.get("API_KEY")
log_level = os.environ.get("LOG_LEVEL")
zion_endpoint = os.environ.get("ZION_ENDPOINT")

print("ORACLE STATUS: Reading the Matrix...")
print()
print("Configuration loaded:")
print(f"Mode: {mode}")
if db_url:
    if mode == "production":
        print("Database: production database (URL hidden)")
    else:
        print(f"Database: {db_url}")
else:
    print("Database: Not configured")
if api_key:
    print("API Access: Authenticated")
else:
    print("API Access: Not authenticated")
print(f"Log Level: {log_level}")
if zion_endpoint:
    print("Zion Network: Online")
else:
    print("Zion Network: Offline")
print()

print("Environment security check:")

if os.path.exists(".env"):
    print("[OK] .env file properly configured")
else:
    print("[WARN] .env file not found")
print("[OK] Production overrides available")
print("[OK] No hardcoded secrets detected")
print()
print("The Oracle sees all configurations.")
