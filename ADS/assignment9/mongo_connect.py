from pymongo import MongoClient

# Connect to MongoDB
client = MongoClient('localhost', 27017)
db = client['mydatabase']
collection = db['mycollection']

# Create Operation
data1 = {'name': 'John', 'age': 30, 'city': 'New York'}
data2 = {'name': 'Emma', 'age': 25, 'city': 'Los Angeles'}
data3 = {'name': 'Michael', 'age': 35, 'city': 'Chicago'}
collection.insert_many([data1, data2, data3])

# Read Operation
result = collection.find_one({'name': 'John'})
print(result)

# Update Operation
collection.update_one({'name': 'John'}, {'$set': {'age': 35}})

# Delete Operation
collection.delete_one({'name': 'Michael'})

# Close connection
client.close()

