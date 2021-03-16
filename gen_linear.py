from random import randrange
import matplotlib.pyplot as plt

def main(a, b, length, error):

    x_list = []
    y_list = []
    out = open("linear.txt", "w")

    for x in range (length):

        y = a*x + b + randrange(error)
        x_list.append(x)
        y_list.append(y)

        out.write(str(x) + " " + str(y) + "\n")
    
    out.close()

    plt.scatter(x_list, y_list, label='linear')
    plt.show()

    return [x_list, y_list]

if __name__ == "__main__":

    main(2.5, 1.9, 2**16, 10)