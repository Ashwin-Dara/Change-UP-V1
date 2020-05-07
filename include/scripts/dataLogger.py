import matplotlib.pyplot as plt

class Logger:
    def __init__(self, file, y_axis, streamArg):
        self.file = file
        self.y_axis = y_axis
        self.streamArg = streamArg
        self.y = []
        
    def visualPlot(self, space, appearance):
        fstream = open(self.file, self.streamArg)
        stream = fstream.readlines()
        for i in stream: 
            self.y.append(float(i))
        self.values = self.y
        plt.yscale("linear")
        self.space = space
        self.appearance = appearance
        plt.axis(self.space)
        plt.plot(self.values, self.appearance)
        plt.ylabel(self.y_axis)
        plt.show()

powerLog = Logger("include\data\powerStreamData.txt", "power(rpm)", "r")

def main():
    
    powerLog.visualPlot([0, 10, 0, 200], 'p')
 #   logger = open("include\data\powerStreamData.txt", "r")
 #   #if logger.mode = "r":
 #   stream = logger.readlines()
 #   for i in stream: 
 #       x.append(i)
 #   plt.plot(x)
 #   plt.show()
    
if __name__ == "__main__":
    main()