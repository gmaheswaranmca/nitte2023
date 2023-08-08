class DemoClassA:
    def __init__(self, inst_var1 = 10):
        self.__inst_var1 = inst_var1

    def get_inst_var1(self):
        return self.__inst_var1

#driver code

demo1 = DemoClassA()
demo2 = DemoClassA()

#print(demo1.__inst_var1)
#print(demo2.__inst_var1)

#demo1.__inst_var1 = 20

print(demo1.get_inst_var1())
print(demo2.get_inst_var1())
