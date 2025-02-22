import requests
import json

def getDataFromAPIandSaveWeatherData():

    API_KEY = "e9545cdd04c74e6c9e4212039242511"
    BASE_URL = "https://api.weatherapi.com/v1"
    url = f"{BASE_URL}/forecast.json?key={API_KEY} &q=London &days=9"

    response = requests.get(url)

    if response.status_code == 200:
        data = response.json()
        try:
            with open('weather_data.json', 'w') as json_file:
                json.dump(data, json_file, indent=4)  
            print("Data has been saved to 'weather_data.json'")
        except Exception as e:
            print("An error occurred while saving data:", e)
            data = []
    else:
        print("Error:", response.status_code)
    
def get_current_temperature(city):
    try:
        with open('weather_data.json', 'r') as json_file:
            data = json.load(json_file)

        if city == data['location']['name']:
            print( data['current']['temp_c'] )

        else:
            print("City not found")
            return False
    except Exception as e:
        print("An error occurred while reading data:", e)
        return False
    
def getTemperatureAfter(city, days, hours=None):

    try:
        with open('weather_data.json', 'r') as json_file:
            data = json.load(json_file)

        if city == data['location']['name']:
            city = data['location']['name']
            if days < len(data['forecast']['forecastday']):
                forecast_day = data['forecast']['forecastday'][days]
                if hours is not None:
                    if 0 <= hours < len(forecast_day['hour']):
                        temperature = forecast_day['hour'][hours]['temp_c']
                        print(f"Temperature in {city}on day {days+1} at hour {hours}: {temperature}°C")
                        return temperature
                    else:
                        print(f"Invalid hour index. Available hours: 0 to {len(forecast_day['hour'])-1}")
                else:
                    # if the user did not enter the hour read the maximum tempreture of the day given
                    max_temp = forecast_day['day']['maxtemp_c']
                    print(f"Maximum temperature on day {days+1}: {max_temp}°C")
        else :
            print("City not found")
            return False
        
    except Exception as e:
        print("An error occurred while reading data:", e)
        return False



def getLatAndLong(city):
    try:
        with open('weather_data.json', 'r') as json_file:
            data = json.load(json_file)

        if city == data['location']['name']:
            print( data['location']['lat'], data['location']['lon'] )

        else:
            print("City not found")
            return False
    except Exception as e:
        print("An error occurred while reading data:", e)
        return False

getDataFromAPIandSaveWeatherData()
get_current_temperature("London")
getTemperatureAfter("London", 2, 5)
getTemperatureAfter("London", 2)
getTemperatureAfter("London", 9 , 5)
getTemperatureAfter("Cairo", 2)
getLatAndLong("London")


# I run this code first to get the number of days in the forecast then I comment it and continue in the code above 
# import json
# # Load the weather data from the saved file
# with open('weather_data.json', 'r') as json_file:
#     data = json.load(json_file)
# # Get the number of days in the forecast
# num_days = len(data['forecast']['forecastday'])
# print(f"Number of days in the forecast: {num_days}")

