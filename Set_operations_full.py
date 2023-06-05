class Set:
    #constructor
    def __init__(self):
        self.elements = []
    
    #Adding element to set
    def add(self , new_element):
        if new_element not in self.elements:
            self.elements.append(new_element)

    #Removing element from set
    def remove(self , new_element):
        if new_element in self.elements:
            self.elements.remove(new_element)
        
    #check for contents 
    def contains(self , new_element):
        return new_element in self.elements
    
    #check for size
    def size(self):
        return len(self.elements)
    
    #check for iterator
    def iterator(self):
        return iter(self.elements)
    
    #Intersection
    def Intersection(self , other_set):
        intersection_set = Set()
        for element in self.elements:
            if element in other_set.elements:
                intersection_set.add(element)
        return intersection_set

    #union
    def Union(self , other_set):
        union_set = Set()
        for element in self.elements:
            union_set.add(element)
        for element in other_set.elements:
            union_set.add(element)
        return union_set
    
    #difference
    def Difference(self , other_set):
        deifference_set = Set()
        for element in self.elements:
            if element not in other_set.elements:
                deifference_set.add(element)
        return deifference_set
    
    #Subset
    def subset(self , other_set):
        for element in self.elements:
            if element not in other_set.elements:
                return False
        return True
    
    #menu

def menu():
    set_1 = Set()
    set_2 = Set()
    while True:
        print("==== Set Operations Menu ====")
        print("1. Add element to Set A")
        print("2. Remove element from Set A")
        print("3. Check if element is in Set A")
        print("4. Get size of Set A")
        print("5. Perform intersection of Set A and Set B")
        print("6. Perform union of Set A and Set B")
        print("7. Get difference between Set A and Set B")
        print("8. Check if Set A is a subset of Set B")
        print("9. Exit")

        choice = int(input("Enter your Choice: "))
        if choice == 1:
            ele = int(input("enter number of elements in set A :"))
            for i in range(ele):
                element = int(input("Enter the element to add: "))
                set_1.add(element)
            print("Elements added to set A")
        
        elif choice == 2:
            element = int(input("Enter the element to remove from set A : "))
            set_1.remove(element)
            print("Element removed successfully")

        elif choice == 3:
            element = int(input("Enter the element to be checked for : "))
            if set_1.contains(element):
                print("Element is in Set A")
            else:
                print("Element is not in set A")

        elif choice == 4:
            print("Size of Set A is ",set_1.size)

        elif choice == 5:
            ele1 = int(input("Enter the number of elements in Set B"))
            for i in range(ele1):
                elem=int(input("Enter the element to add : "))
                set_2.add(elem)
            print("Elements Added to set B")
            print("Intersection of Set A and Set B is", set_1.Intersection(set_2).elements)

        elif choice == 6:
            print("Union of Set A and Set B is ",set_1.Union(set_2).elements)

        elif choice == 7:
            print("Difference of set A and Set B is ",set_1.Difference(set_2).elements)

        elif choice == 8:
            if set_1.subset(set_2):
                print("Set A is subset of Set B")
            else:
                print("Set A is not a subset of set B")
        
        elif choice == 9:
            print("Exiting the program ")

        else:
            print("Invalid choice. Please Try again")

            
menu()
        
