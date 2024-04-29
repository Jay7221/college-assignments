from cassandra.cluster import Cluster

# Connect to Cassandra
cluster = Cluster(['localhost'])
session = cluster.connect()

# Execute a query
session.execute("CREATE KEYSPACE IF NOT EXISTS test_keyspace WITH replication = {'class': 'SimpleStrategy', 'replication_factor': 1}")
session.execute("USE test_keyspace")
session.execute("CREATE TABLE IF NOT EXISTS test_table (id UUID PRIMARY KEY, name TEXT, age INT)")
session.execute("INSERT INTO test_table (id, name, age) VALUES (uuid(), 'John', 30)")

# Retrieve and print the inserted data
rows = session.execute("SELECT * FROM test_table")
for row in rows:
    print(row)

# Close the connection
cluster.shutdown()

