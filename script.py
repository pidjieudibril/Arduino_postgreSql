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

try:
    # Boucle principale de lecture des données du capteur et stockage dans la base de données
    while True:
        # Lecture des données du capteur depuis le port série
        data = ser.readline().decode('ascii').strip()
        
        # Vérification si les données sont valides
        if data:
            # Extraction des valeurs de capteur de distance et de toucher 
            distance= data.split(" ")
            
            # Insertion des données dans la base de données
            query = f"INSERT INTO capteur (nom_capteur) VALUES ({distance})"
            cursor = conn.cursor()
            cursor.execute(query)
            conn.commit()
            
            print(f"Données insérées : nom_capteur = {distance}")
except KeyboardInterrupt:
    # Fermeture du port série et de la connexion PostgreSQL en cas d'interruption du programme
    ser.close()
    conn.close()
    print("Programme arrêté")
