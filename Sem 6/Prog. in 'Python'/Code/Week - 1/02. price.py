price = float(input("Enter the price of the item: "))
rate = float(input("Enter the tax rate of the item: "))
print("Final price including tax is: ", price*(rate/100) + price )