
class Sequential()
    def __init__(self, inputDim, useCuda = False):
        self.inputDim = inputDim
        self.weights = []
        self.dweights = []
        self.units = [[0 for i in range(self.inputDim)]]
        self.units[-1].append(1) # bias unit
        self.duints = [[0 for i in range(self.inputDim+1)]]
        self.activations = []
    # add a Dense Layer
    def add(self, num, activation="sigmoid", input_dim=8):
        self.activations.append(activation)
        self.weights.append([[0 for i in range(len(self.units[-1]))] for j in range(num)])
        self.dweights.append([[0 for i in range(len(self.units[-1]))] for j in range(num)])
        self.units.append([0 for i in range(num)])
        self.units[-1].append(1) # bias unit


    def forward(self, x):
        for i in range(len(self.units)):
            for j in range(len(self.units)-1):
                self.units[i][j] = 0
        for i,w in enumerate(self.weights):
                for j,z in enumerate(w):
                    self.units[i+1][j] += sum([u*self.units[i][m] for m,u in enumerate(z)])
                    if self.activations[i] == "sigmoid":
                        self.units[k+1][j] = 1/(1+ e**(-1*self.units[i+1][j]))

    def backward(self, y):
        error = [self.units[-1][i]-y[i] for i in range(len(y))]
        for i in range(len(y)):
            self.dunits[-1][i] = self.units[-1][i]-y[i]

        for i in range(1,len(self.dunits)+1):
            if self.activations[-1*i] == "sigmoid"
                for j,w in self.dweights
            for j in range(len(self.dunits[-1*i])):

    def gradient(self):
        pass


    def fit(self, X, Y, epochs, batchSize):
        pass

    def evaluate(self, X, Y):
        pass
