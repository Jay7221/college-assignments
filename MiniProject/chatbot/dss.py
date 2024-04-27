def decision_support(disease_risk_level, location, grape_variety):
    # Dictionary to store water and nutrient requirements for different scenarios
    water_requirements = {
        "nil": {"Sangli": {"thompson seedless": "low", "red globe": "low"},
                "Solapur": {"thompson seedless": "low", "red globe": "low"},
                "Nashik": {"thompson seedless": "low", "red globe": "low"}},
        "low": {"Sangli": {"thompson seedless": "medium", "red globe": "medium"},
                "Solapur": {"thompson seedless": "medium", "red globe": "medium"},
                "Nashik": {"thompson seedless": "medium", "red globe": "medium"}},
        "moderate": {"Sangli": {"thompson seedless": "high", "red globe": "high"},
                     "Solapur": {"thompson seedless": "high", "red globe": "high"},
                     "Nashik": {"thompson seedless": "high", "red globe": "high"}},
        "high": {"Sangli": {"thompson seedless": "very high", "red globe": "very high"},
                 "Solapur": {"thompson seedless": "very high", "red globe": "very high"},
                 "Nashik": {"thompson seedless": "very high", "red globe": "very high"}},
        "very high": {"Sangli": {"thompson seedless": "extremely high", "red globe": "extremely high"},
                      "Solapur": {"thompson seedless": "extremely high", "red globe": "extremely high"},
                      "Nashik": {"thompson seedless": "extremely high", "red globe": "extremely high"}}
    }

    nutrient_requirements = {
        "nil": {"Sangli": {"thompson seedless": "low", "red globe": "low"},
                "Solapur": {"thompson seedless": "low", "red globe": "low"},
                "Nashik": {"thompson seedless": "low", "red globe": "low"}},
        "low": {"Sangli": {"thompson seedless": "medium", "red globe": "medium"},
                "Solapur": {"thompson seedless": "medium", "red globe": "medium"},
                "Nashik": {"thompson seedless": "medium", "red globe": "medium"}},
        "moderate": {"Sangli": {"thompson seedless": "high", "red globe": "high"},
                     "Solapur": {"thompson seedless": "high", "red globe": "high"},
                     "Nashik": {"thompson seedless": "high", "red globe": "high"}},
        "high": {"Sangli": {"thompson seedless": "very high", "red globe": "very high"},
                 "Solapur": {"thompson seedless": "very high", "red globe": "very high"},
                 "Nashik": {"thompson seedless": "very high", "red globe": "very high"}},
        "very high": {"Sangli": {"thompson seedless": "extremely high", "red globe": "extremely high"},
                      "Solapur": {"thompson seedless": "extremely high", "red globe": "extremely high"},
                      "Nashik": {"thompson seedless": "extremely high", "red globe": "extremely high"}}
    }

    # Getting water and nutrient requirements based on input parameters
    water_requirement = water_requirements[disease_risk_level][location][grape_variety]
    nutrient_requirement = nutrient_requirements[disease_risk_level][location][grape_variety]

    # Returning water and nutrient requirements
    return water_requirement, nutrient_requirement


# Example usage:
disease_risk_level = "moderate"
location = "Nashik"
grape_variety = "red globe"
water_requirement, nutrient_requirement = decision_support(
    disease_risk_level, location, grape_variety)
print("Water requirement:", water_requirement)
print("Nutrient requirement:", nutrient_requirement)
