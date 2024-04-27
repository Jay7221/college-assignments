import requests
import datetime

def get_weather(date_str, api_key, location):
  """Fetches weather data for a given location and date.

  Args:
      date_str: String in the format "DD Month YYYY".
      api_key: Your OpenWeatherMap API key.
      location: The location for which to get the weather.

  Returns:
      A dictionary containing weather information or None if an error occurs.
  """

  try:
    # Parse the date string
    date_obj = datetime.datetime.strptime(date_str, "%d %B %Y")

    # Convert date to YYYY-MM-DD format
    formatted_date = date_obj.strftime("%Y-%m-%d")

    # Build the API request URL
    url = f"https://api.openweathermap.org/data/2.5/weather?q={location}&appid={api_key}&dt={formatted_date}"

    # Make the API request
    response = requests.get(url)
    response.raise_for_status()  # Raise an exception for non-200 status codes

    # Parse the JSON response
    data = response.json()
    return data

  except (requests.exceptions.RequestException, ValueError) as e:
    print(f"An error occurred while fetching weather data: {e}")
    return None

# Example usage (replace with your API key)
api_key = "7a17c4f953f8c9e4e8701d84b9264f00"
date_str = "14 July 2023"

weather_data = get_weather(date_str, api_key, "Sangli")

if weather_data:
  print("Weather data:")
  # Access weather information from the data dictionary (e.g., temperature, description)
  # ...
else:
  print("Failed to retrieve weather data.")

