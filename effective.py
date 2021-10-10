

'''
第7条： 用列表推导来取代map和filter
'''
def clause7():
    a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    alt = map(lambda x: x**2, filter(lambda x: x % 2 == 0, a))
    print(list(alt))
    '''
    [4, 16, 36, 64, 100]
    '''

    '''
    列表推导比内置的map和filter函数清晰，因为它无需额外编写lambda表达式
    '''
    even_squares = [x**2 for x in a if x % 2 == 0]
    print(even_squares)
    '''
    [4, 16, 36, 64, 100]
    '''

    '''
    字典与集也支持推导表达式
    '''
    color_indexs = {'red': 1, 'green': 2, "yellow": 3, "blue": 4}
    indexs_color = {index : color for color, index in color_indexs.items()}
    print(indexs_color)
    '''
    {1: 'red', 2: 'green', 3: 'yellow', 4: 'blue'}
    '''

'''
第8条： 不要使用含有两个以上表达式的列表推导
'''
def clause8():
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    flat = [x for row in matrix for x in row]
    print(flat)
    '''
    [1, 2, 3, 4, 5, 6, 7, 8, 9]
    '''

    squared = [[x**2 for x in row] for row in matrix]
    print(squared)
    '''
    [[1, 4, 9], [16, 25, 36], [49, 64, 81]]
    '''

    filtered = [[x for x in row if x % 3 == 0]
                for row in matrix if sum(row) >= 10]
    print(filtered)
    '''
    [[6], [9]]
    '''
    '''
    上面这个例子看似符合用列表推导来实现的情况，但强烈建议尽量不要编写这种包含
    复杂式子的列表推导，因为这样的代码往往难以理解。复杂的情况下应该使用普通的
    if和for语句。
    '''

'''
第9条： 用生成器表达式来改写数据量较大的列表推导
当输入的数据量较大时，列表推导会可能因为占用太多内存而出问题，由生成器表达式所返回的迭代器，
可以逐次产生输出值，从而避免了内存用量问题。
'''
def clause9():
    '''
    下面语句会因为内存不足而运行失败
    '''
    # value = [x for x in range(0, 999999999)]

    it = (x for x in range(0, 999999999))
    print(it)
    print(next(it))
    print(next(it))
    '''
    <generator object clause9.<locals>.<genexpr> at 0x7f3640ad66d0>
    0
    1
    '''

    roots = ((x, x**0.5) for x in it)
    print(next(roots))
    print(next(roots))
    '''
    (2, 1.4142135623730951)
    (3, 1.7320508075688772)
    '''

'''
第10条： 尽量使用enumerate取代range
'''
def clause10():
    flavor_list = ['vanilla', 'chocolate', 'pecan', 'strawberry']
    for i in range(len(flavor_list)):
        flavor = flavor_list[i]
        print("%d : %s" %(i+1, flavor))
    
    for i, flavor in enumerate(flavor_list):
        print("%d : %s" %(i+1, flavor))
    
    for i, flavor in enumerate(flavor_list, 1):     # 指定初始计数
        print("%d : %s" %(i+1, flavor))
    '''
    2 : vanilla
    3 : chocolate
    4 : pecan
    5 : strawberry
    '''

'''
第11条： 用zip函数同时遍历两个迭代器
'''
def clause11():
    names = ['Cecilia', 'Lise', 'Marie']
    letters = [len(n) for n in names]

    for name, count in zip(names, letters):
        print(name, count)
    '''
    zip函数，可以把两个或两个以上的迭代器封装成生成器，以便稍后求值。这种zip生成器
    会从每个迭代器中获取该迭代器的下一个值，然后把这些值汇聚成元组。
    '''

'''
第12条： 不要在for和while循环后面写else块
'''

'''
第13条： 合理利用try/except/else/finally结构中的每个代码块
- 无论try块是否发生异常，都可以利用try/finally复合语句中的finally块来执行清理工作
- else块可以用来缩减try块中的代码量，并把没有发生异常时所要执行的语句与try/except代码块隔开
- 顺利运行try块后，若想使某些操作能在finally块的清理代码之前执行，则可将这些操作写到else块中
'''

def clause13():
    def func(path):
        handle = open(path, 'r+')
        try:
            data = handle.read()
        except IOError as e:
            return 0            # 异常时执行
        else:
            return 1            # 没异常时执行
        finally: 
            handle.close()      # 总会执行

'''
第21条：用只能以关键字形式指定的参数来确保代码明晰
参数列表里的*号，标志着位置参数就此终结，之后的那些参数
都只能以关键字形式来指定。
'''

def clause21(param1, param2, *, param3=False):
    pass

'''
第27条： 多用public属性，少用private属性
'''

class Parent(object):
    def __init__(self, val):
        self.__val = val            #双下划线开头的为private属性

class Child(Parent):
    def __init__(self, val):
        super().__init__(val)
    
    def get_privete_filed(self):
        # return self.__val         #此句会报错
        return self._Parent__val    
        '''
        上面这句不会报错，因为pyhton并没从语法上严格限制子类不能访问父类
        private属性，只是会把名字给转换了一下。
        '''

def clause27():
    obj = Child(523)
    print(obj.get_privete_filed())

'''
第30条：考虑用@property来代替属性重构

'''

class Student(object):
    def __init__(self, name, age):
        self.__name = name
        self.__age = age
    '''
    由于python进行属性的定义时，没办法设置私有属性，因此可以通过设置
    @property的方法来进行设置。这样可以隐藏属性名，让用户进行使用的时候无法随机修改。
    '''
    @property
    def age(self):
        return self.__age

    @age.setter
    def age(self, val):
        self.__age = val

def clause30():
    student = Student("xyh", 23)
    print(student.age)
    student.age = 24
    print(student.age)

'''
第32条：用__getattr__、__getattribute__和__setattr__实现按需生成的属性

- 获取一个对象的属性时，首先在__dict__中寻找，然后再调用__getattr__方法
- __getattr__方法只会调用一次
- __getattribute__方法每次在对象上调用hasattr或getattr函数时，此方法都会执行

'''

class LazyDB(object):
    def __init__(self):
        self.exists = 5
    
    def __getattr__(self, name):
        value = 'Value for %s' % name
        setattr(self, name, value)
        return value

class LoggingLazyDB(LazyDB):
    def __getattr__(self, name):
        print("Called __getattr__(%s)" % name)
        return super().__getattr__(name)        #防止递归调用


class VaildatingDB(object):
    def __init__(self):
        self.exists = 5
    
    def __getattribute__(self, name):
        print('Called __getattribute__(%s)' % name)
        try:
            return super().__getattribute__(name)
        except AttributeError:
            value = 'Value for %s' % name
            setattr(self, name, value)
            return value

def clause32():
    db = VaildatingDB()
    print('exists: ', db.exists)
    print('foo:    ', db.foo)
    print('foo:    ', db.foo)



if __name__ == '__main__':
    clause32()
