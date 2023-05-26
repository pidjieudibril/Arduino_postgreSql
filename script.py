import psycopg2
import serial

# Paramètres de connexion PostgreSQL
hostname = 'localhost'
database = 'testgesprime'
username = 'postgres'
pwd = 'admin'
port_id = 5432

# Paramètres du port série Arduino
port_name = 'COM5'
baud_rate = 9600





# Connexion à la base de données PostgreSQL
conn = psycopg2.connect(
    host=hostname,
    port=port_id,
    database=database,
    user=username,
    password=pwd
)
print("Connexion à PostgreSQL réussie")

# Ouverture du port série Arduino
ser = serial.Serial(port_name, baud_rate)
print("Port série ouvert")

while True:
    # Lire les données des capteurs depuis l'Arduino
    data1 = ser.readline().decode("ascii").strip()
    data2 = ser.readline().decode("ascii").strip()

    # Insérer les données dans la base de données PostgreSQL
    query = f"INSERT INTO capteur (id_c,nom_capteur, distance) VALUES (1,'{data1}', '{data2}')"
    cursor = conn.cursor()
    cursor.execute(query)
    conn.commit()

    print("Données insérées avec succès - Capteur 1 :", data1)
    print("Données insérées avec succès - Capteur 2 :", data2)

# Fermer la connexion avec la base de données PostgreSQL
cur.close()
conn.close()
