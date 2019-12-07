import sqlite3

def create_db_and_table():
	#database
	conn = sqlite3.connect("towed-cars.db")
	cursor = conn.cursor()
	sql1 = "CREATE TABLE Towed_Cars(date text, make text, style text, model text, color text, plate text, state text, address text)"
	cursor.execute(sql1)
	cursor.close()

def add_cvs_to_database():
   
    conn = sqlite3.connect("towed-cars.db")
    cursor = conn.cursor()

    with open("towed_vehicles_city_of_chicago.csv", "r") as f:
         for line in f:
         	if not line.startswith("TOW DATE"):
         		line = line.replace("\n","")
         		L = line.split(",")
         		date = L[0]
         		make = L[1]
         		style = L[2]
         		model = L[3]
         		color = L[4]
         		plate = L[5]
         		state = L[6]
         		address = L[7]
         		sql = "INSERT INTO Towed_Cars(date, make, style, model, color, plate, state, address) VALUES (:date, :make, :style, :model, :color, :plate, :state, :address)"
         		cursor.execute(sql, {"date":date, "make":make, "style":style, "model":model, "color":color, "plate":plate, "state":state, "address":address})
    conn.commit()
    cursor.close()


def display_all_db_data():
    conn = sqlite3.connect('towed-cars.db')
    cursor = conn.cursor()
    sql = "SELECT * FROM Towed_Cars" # * shorthand for all columns of the table
    columns = cursor.execute(sql)
    all_entries = columns.fetchall()
    for entry in all_entries:
        print(entry)

def cars_out_of_state():
	conn = sqlite3.connect('towed-cars.db')
	cursor = conn.cursor()
	sql1 = "SELECT COUNT(state) FROM Towed_Cars where state != 'IL'"
	state_columns = cursor.execute(sql1)
	out_state = state_columns.fetchall()[0]
	for state in out_state:
		print(out_state)

def states_towed():
	conn = sqlite3.connect('towed-cars.db')
	cursor = conn.cursor()
	sql2 = "SELECT state FROM Towed_Cars where state != 'IL' ORDER BY state"
	states_columns = cursor.execute(sql2)
	all_states = states_columns.fetchall()
	for states in all_states:
		print(states)

def towing_locations():
	conn = sqlite3.connect('towed-cars.db')
	cursor = conn.cursor()
	sql3 = "SELECT DISTINCT COUNT(address) FROM Towed_Cars"
	Towed_columns = cursor.execute(sql3)
	towed = Towed_columns.fetchall()[0]
	print(towed)

def date_towed():
	conn = sqlite3.connect('towed-cars.db')
	cursor = conn.cursor()
	sql4 = "SELECT MAX(date) FROM Towed_Cars where date != 'Tow Date'"
	date = cursor.execute(sql4).fetchall()[0]
	print(date)

def vehicle_make():
	conn = sqlite3.connect('towed-cars.db')
	cursor = conn.cursor()
	sql5 = "SELECT DISTINCT MIN(make) FROM Towed_Cars where make != ''"
	make = cursor.execute(sql5).fetchall()[0]
	print(make)


def main():
	create_db_and_table()
	add_cvs_to_database()
	display_all_db_data()
	cars_out_of_state()
	states_towed()
	towing_locations()
	date_towed()
	print("April 12th was a friday.")
	vehicle_make()
	
main()
