from . import light_spellbook


def validate_ingredients(ingredients: str) -> str:
    allowed = light_spellbook.light_spell_allowed_ingredients()
    for i in allowed:
        if i in ingredients.lower():
            return (f"{ingredients} - VALID")
    return (f"{ingredients} - INVALID")
