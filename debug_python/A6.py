import arcpy as arc

# Defining function

def printer (workspace, featureClass, overwrite=True): #fixed syntaxerror of double =
    arc.env.overwriteoutput = overwrite
    env.workspace = "C:/Data"
    desc = arc.Describe("facilities.shp")
    spatialref = desc_spatialReference

    # Writing NAMES field from Shapefile features to list
    cursor = arcpy.da.SearchCursor(src_file,'OID@','NAME')
    names = ()  
    for row in cursor: #Took out [,] and replaced with [:] for the for-loop
        names.append(row[2])

    # Sorting facilities by name (ascending order)
    names.sort

    # Printing sorted facilities
    counter = 0
    while entry in names:
        counter +=1 #Take away space between [+] and = and [1] to excute add
        print ("{0}. (1)".format(counter, entry))

    # Setting environmental parameters to default values
    arc.env.workspace = "C:/GISCLASS/GIST603A/Data/Unit6" #Changed to have double ""

# Setting parameters from C:/Data/Unit6/facilities.shp

workspace = "C:/Data//Unit6"
featureClass = facilities.shp

# Running function
printer(workspace,featureClass)
