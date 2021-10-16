'''
__filename__ = "statecapitalbird.py"
__coursename__ = "SDEV 300 6380 - Building Secure Web Applications (2198)"
__author__ = "Lourdes Cigarruista"
__copyright__ = "None"
__credits__ = ["Lourdes Cigarruista"]
__license__ = "GPL"
__version__ = "1.0.0"
__maintainer__ = "Lourdes Cigarruista"
__email__ = "lcigarruista@student.umuc.edu"
__status__ = "program that will allow the user to see all state capitals, flowers and birds,
it will also allow the user to update the bird if needed"
'''


class x_state:
    def __init__(self, name_of_state, capital, bird, flower):
        self.name_of_state = name_of_state
        self.capital = capital
        self.bird = bird
        self.flower = flower

    def change_bird(self, bird):
        self.bird = bird

def change_bird_to_new(realm_list, name_of_state, bird_name):
        for x_state in realm_list:
            if x_state.name_of_state == name_of_state:
                x_state.change_bird(bird_name)

def show_states_inorder(realm_list):
    for x_state in sorted([x_state.name_of_state for x_state in realm_list]):
        for state_info in realm_list:
            if x_state == state_info.name_of_state:
                print("State Name: ", state_info.name_of_state,
                        "\n\tCapital: ", state_info.capital,
                        "\n\tBird: ",   state_info.bird,
                        "\n\tFlower: ",  state_info.flower)

def show_state(realm_list, x_state):
    state_found = False
    for info_of_state in realm_list:
        if info_of_state.name_of_state == x_state:
            state_found = True
            print("State Name: ", state_info.name_of_state,
                   "\n\tCapital: ", state_info.capital,
                   "\n\tBird: ", state_info.bird,
                   "\n\tFlower: ", state_info.flower)
        if state_found == False:
                print("Sorry, there's no state with that information")


if __name__ == "__main__":
    realm_list = []

    x = x_state('Alabama', 'Montgomery', 'Yellowhammer', 'Camellia')
    realm_list.append(x)
    x = x_state('Alaska', 'Juneau', 'Willow Ptarmigan', 'Forget Me Not')
    realm_list.append(x)
    x = x_state('Arizona', 'Phoenix', 'Cactus Wren', 'Saguaro Cactus Blossom')
    realm_list.append(x)
    x = x_state('Arkansas', 'Little Rock', 'Mockingbird', 'Apple Blossom')
    realm_list.append(x)
    x = x_state('California', 'Sacramento', 'California Valley Quail', 'California Poppy')
    realm_list.append(x)
    x = x_state('Colorado', 'Denver', 'Lark Bunting', 'White and Lavender Columbine')
    realm_list.append(x)
    x = x_state('Connecticut', 'Hartford', 'Robin', 'Mountain Laurel')
    realm_list.append(x)
    x = x_state('Delaware', 'Dover', 'Blue Hen', 'Peach Blossom')
    realm_list.append(x)
    x = x_state('Florida', 'Tallahassee', 'Mockingbird', 'Orange Blossom')
    realm_list.append(x)
    x = x_state('Georgia', 'Atlanta', 'Brown Thrasher', 'Cherokee Rose')
    realm_list.append(x)
    x = x_state('Hawaii', 'Honolulu', 'Nene', 'Hibiscus')
    realm_list.append(x)
    x = x_state('Idaho', 'Boise', 'Mountain Bluebird', 'Syringa')
    realm_list.append(x)
    x = x_state('Illinois', 'Indianapolis', 'Cardinal', 'Purple Violet')
    realm_list.append(x)
    x = x_state('Indiana', 'Montgomery', 'Cardinal', 'Peony')
    realm_list.append(x)
    x = x_state('Iowa', 'Des Moines', 'Eastern Goldfinch', 'Wild Prairie Rose')
    realm_list.append(x)
    x = x_state('Kansas', 'Topeka', 'Western Meadowlark', 'Sunflower')
    realm_list.append(x)
    x = x_state('Kentucky', 'Frankfort', 'Cardinal', 'Goldenrod')
    realm_list.append(x)
    x = x_state('Louisiana', 'Baton Rouge', 'Brown Pelican', 'Magnolia')
    realm_list.append(x)
    x = x_state('Maine', 'Augusta', 'Chickadee', 'White Pine Cone and Tassel')
    realm_list.append(x)
    x = x_state('Maryland', 'Annapolis', 'Baltimore Oriole', 'Black-Eyed Susan')
    realm_list.append(x)
    x = x_state('Massachusetts', 'Boston', 'Chickadee', 'Mayflower')
    realm_list.append(x)
    x = x_state('Michigan', 'Lansing', 'Robin', 'Apple Blossom')
    realm_list.append(x)
    x = x_state('Minnesota', 'Saint Paul', 'Common Loon', 'Pink and White Lady Slipper')
    realm_list.append(x)
    x = x_state('Mississippi', 'Jackson', 'Mockingbird', 'Magnolia')
    realm_list.append(x)
    x = x_state('Missouri', 'Jefferson City', 'Bluebird', 'White Hawthorn Blossom')
    realm_list.append(x)
    x = x_state('Montana', 'Helena', 'Western Meadowlark', 'Bitterroot')
    realm_list.append(x)
    x = x_state('Nebraska', 'Lincoln', 'Western Meadowlark', 'Goldenrod')
    realm_list.append(x)
    x = x_state('Nevada', 'Carson City', 'Mountain Bluebird', 'Sagebrush')
    realm_list.append(x)
    x = x_state('New Hampshire', 'Concord', 'Purple Finch', 'Purple Lilac')
    realm_list.append(x)
    x = x_state('New Jersey', 'Trenton', 'Goldfinch', 'Violet')
    realm_list.append(x)
    x = x_state('New Mexico', 'Santa Fe', 'Roadrunner', 'Yucca Flower')
    realm_list.append(x)
    x = x_state('New York', 'Albany', 'Bluebird', 'Rose')
    realm_list.append(x)
    x = x_state('North Carolina', 'Raleigh', 'Cardinal', 'Dogwood')
    realm_list.append(x)
    x = x_state('Ohio', 'Columbus', 'Cardinal', 'Scarlet Carnation')
    realm_list.append(x)
    x = x_state('Oklahoma', 'Oklahoma City', 'Scissor-Tailed Flycatcher', 'Mistletoe')
    realm_list.append(x)
    x = x_state('Oregon', 'Salem', 'Western Meadowlark', 'Oregon Grape')
    realm_list.append(x)
    x = x_state('Pennsylvania', 'Harrisburg', 'Ruffed Grouse', 'Mountain Laurel')
    realm_list.append(x)
    x = x_state('Rhode Island', 'Providence', 'Rhode Island Red', 'Violet')
    realm_list.append(x)
    x = x_state('South Carolina', 'Columbia', 'Great Carolina Wren', 'Yellow Jessamine')
    realm_list.append(x)
    x = x_state('North Dakota', 'Bismarck', 'Western Meadowlark', 'Wild Prairie Rose')
    realm_list.append(x)
    x = x_state('South Dakota', 'Pierre', 'Ring-Necked Pheasant', 'Pasque Flower')
    realm_list.append(x)
    x = x_state('Tennessee', 'Nashville', 'Mockingbird', 'Iris')
    realm_list.append(x)
    x = x_state('Texas', 'Austin', 'Mockingbird', 'Bluebonnet')
    realm_list.append(x)
    x = x_state('Utah', 'Salt Lake City', 'California Seagull', 'Sego Lily')
    realm_list.append(x)
    x = x_state('Vermont', 'Montpelier', 'Hermit Thrush', 'Red Clover"')
    realm_list.append(x)
    x = x_state('Virginia', 'Richmond', 'Cardinal', 'Dogwood')
    realm_list.append(x)
    x = x_state('Washington', 'Olympia', 'Willow Goldfinch', 'Pink Rhododendron')
    realm_list.append(x)
    x = x_state('West Virginia', 'Charleston', 'Cardinal', 'Rhododendron')
    realm_list.append(x)
    x = x_state('Wisconsin', 'Madison', 'Robin', 'Wood Violet')
    realm_list.append(x)
    x = x_state('Wyoming', 'Cheyenne', 'Western Meadowlark', 'Indian Paintbrush')
    realm_list.append(x)

INPUT_FROM_USER = 0

while INPUT_FROM_USER != 4:
    print("\nWelcome to the U.S States with Capital and Home Bird Program! ")
    print("******* Please make a selection **********")
    print("\n1. Display all U.S. States in Alphabetical order along with Capital and Bird")
    print("2. Search for a specific state and display the appropriate Capital and Bird")
    print("3. Update a Bird for a specific state")
    print("4. Exit the program")
    break

INPUT_FROM_USER = int(input("Enter your choice: "))

if INPUT_FROM_USER == 1:
    show_states_inorder(realm_list)
elif INPUT_FROM_USER == 2:
    name_of_state = input("\nEnter State Name: ")
    show_state(realm_list, name_of_state)
elif INPUT_FROM_USER == 3:
    name_of_state = input("\nEnter State Name: ")
    bird_name = input("\nEnter Bird Name: ")
    update_bird_for_State(realm_list, name_of_state, bird_name)
elif INPUT_FROM_USER == 4:
        print("Thank you for using the program for the US States")
        sys.exit()