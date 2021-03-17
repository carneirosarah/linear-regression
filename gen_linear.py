from random import randrange
import matplotlib.pyplot as plt

def main(a, b, length, error):

    if error >= 0:
        
        x_list = []
        y_list = []
        out = open("linear.txt", "w")

        for x in range (length):

            y = b*x + a + randrange(error) if error > 0 else b*x + a
            
            x_list.append(x)
            y_list.append(y)

            out.write(str(x) + " " + str(y) + "\n")

        out.close()

        plt.scatter(x_list, y_list, label='linear')
        plt.show()

        return [x_list, y_list]
    
    else:

        return None

if __name__ == "__main__":

    main(10, 5, 2**16, 0)