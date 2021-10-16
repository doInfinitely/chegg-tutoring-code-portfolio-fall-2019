from numpy import loadtxt
import numpy as np
from keras.models import Sequential
from keras.layers import Dense

def get_model():
    # read csv
    dataset = loadtxt('wine.csv', delimiter=',')
    # split target and feature values
    X = dataset[:,1:14]
    y = dataset[:,0]
    # convert the target data to 1 hot encoding
    y = np.array([[int(x==1), int(x==2), int(x==3)] for x in y])
    # sequential model constructor
    model = Sequential()
    # add Dense 13 unit layer, set input layer length to 13
    model.add(Dense(13, input_dim=13, activation='relu'))
    # add Dense 13 unit layer
    model.add(Dense(13, activation='relu'))
    # add Dense 13 unit laye
    model.add(Dense(13, activation='relu'))
    # add 3 unit softmax layer
    model.add(Dense(3, activation='softmax'))
    # compile model
    model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])
    # train model
    model.fit(X, y, epochs=150, batch_size=10)
    #_, accuracy = model.evaluate(X, y)
    #print('Accuracy: %.2f' % (accuracy*100))
    return model

if __name__=='__main__':
    get_model()
