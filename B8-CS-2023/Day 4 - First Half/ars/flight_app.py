from flight_service import FlightService
from flight import Flight

class FlightView:
    def AddFlightAction(self):
        flight_number = input("Enter Flight Number:")
        airline_name = input("Enter Airline Name:")
        source = input("Enter Source:")
        destination = input("Enter Destination:")
        travel_date = input("Enter Travel Date(yyyy-mm-dd):")
        seats_capacity = int(input("Enter Seats Capacity:"))
        ticket_fare  = float(input("Enter Ticket Fare:"))

        flight = Flight(flight_number, airline_name, 
            source, destination, travel_date, 
            seats_capacity, ticket_fare)
        service = FlightService()
        service.AddFlight(flight)
        print("Flight has added successfully")
    def AppMenu(self):
        print("************Flight Management**********")
        print("""1-Add Flight 
2-Update Price
3-Delete Flight By ID
4-View By Id
5-List All Flights
0-Exit
""")
        menu = int(input())

        if 1 == menu:
            self.AddFlightAction()
        #...

        return menu
    def App(self):
        menu = self.AppMenu()
        while(menu != 0):
            menu = self.AppMenu()


#driver code 
view = FlightView()
view.App()


        