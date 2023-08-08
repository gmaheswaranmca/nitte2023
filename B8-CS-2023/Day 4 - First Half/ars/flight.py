class Flight:
    def __init__(self, flight_number, airline_name, 
            source, destination, travel_date, 
            seats_capacity, ticket_fare):
        self.flight_number = flight_number
        self.airline_name = airline_name
        self.source = source
        self.destination = destination
        self.travel_date = travel_date
        self.seats_capacity = seats_capacity
        self.ticket_fare = ticket_fare
    def __str__(self):
        return f"""[{self.flight_number},
        {self.airline_name},
        {self.source},
        {self.destination},
        {self.travel_date},
        {self.seats_capacity},
        {self.ticket_fare}]"""

