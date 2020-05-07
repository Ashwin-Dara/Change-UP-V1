import matplotlib.pyplot as plt

class Logger:
    x = 10
    def __init__(self, file, y_axis, streamArg):
        self.file = file
        self.y_axis = y_axis
        self.streamArg = streamArg
        self.y = []
    
    def visualPlot(self, space):
        fstream = open(self.file, self.streamArg)
        stream = fstream.readlines()
        for i in stream: 
            self.y.append(i)
        self.values = self.y
        plt.yscale("linear")
        self.space = space
        plt.axis(self.space)
        plt.plot([1, 2, 3], self.values, 'ro')
        plt.ylabel(self.y_axis)
        plt.show()

powerLog = Logger("include\data\powerStreamData.txt", "power(rpm)", "r")

def main():
    powerLog.visualPlot([0, 4, 0, 4])

    print(x)
 #   logger = open("include\data\powerStreamData.txt", "r")
 #   #if logger.mode = "r":
 #   stream = logger.readlines()
 #   for i in stream: 
 #       x.append(i)
 #   plt.plot(x)
 #   plt.show()
    
if __name__ == "__main__":
    main()