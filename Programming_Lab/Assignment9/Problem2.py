class Time:
    def __init__(self, hours, minutes):
        self.hours = hours + minutes // 60
        self.minutes = minutes % 60

    def addTime(self, time):
        self.minutes = self.minutes + time.minutes
        self.hours = self.hours + time.hours + (self.minutes // 60)
        self.minutes = self.minutes % 60

    def displayTime(self):
        print(f'Time is %d hours, %d minutes' % (self.hours, self.minutes))

    def displayMinutes(self):
        print(f'Time is %d minutes' % (self.minutes + 60 * self.hours))

hours = int(input("Enter number of hours : "))
minutes = int(input("Enter number of minutes : "))
tm = Time(hours, minutes)
tm.displayTime()
tm.displayMinutes()
