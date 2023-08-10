import pymysql
def Db():
    con = pymysql.connect(host = "localhost",
            port = 3306,
            database = "college",
            user = "root",
            password = "")
    return con 

def AddStudent():
    name = input("Enter name:")
    usn = input("Enter student usn:")
    course = input("Enter course:")
    age =  int(input("Enter age:"))

    con = Db() 
    cur = con.cursor()
    sql = """INSERT INTO student(name, usn, course, age)
                         VALUES(%s, %s, %s, %s)"""
    params=(name, usn, course, age)
    cur.execute(sql, params)
    con.commit()
    con.close()
    print("Student Added successfull!!!\n\n")

def ListAllStudents():
    con = Db() 
    cur = con.cursor()
    sql = """SELECT * FROM student"""
    params=()
    cur.execute(sql, params)
    students = cur.fetchall()
    con.close()

    print("Name\tUSN\tCourse\tAge")
    for e in students:
        print(f"{e[0]}\t{e[1]}\t{e[2]}\t{e[3]}")
    print("\n\n")

def EditStudent():
    usn = input("Enter student usn:")
    con = Db() 
    cur = con.cursor()
    sql = """SELECT * FROM student
                WHERE usn = %s"""
    params=(usn,)
    cur.execute(sql,params)
    oldStudent = cur.fetchone()
    if oldStudent == None:
        con.close()
        print("No student found")
        return
    name =  input(f"Enter name ({oldStudent[0]}):")
    name = oldStudent[0] if name == "" else name
    course = input(f"Enter course({oldStudent[2]}):")
    course = oldStudent[2] if course == "" else course
    age =  int(input(f"Enter new age({oldStudent[3]}):"))

    sql = """UPDATE student set name=%s, course=%s, age=%s
                         WHERE usn=%s"""
    params=(name, course, age, usn)
    cur.execute(sql, params)
    con.commit()
    con.close()
    print("Student Updated successfully!!!\n\n")

def DeleteStudent():
    usn = input("Enter student usn:")
    con = Db() 
    cur = con.cursor()
    sql = """SELECT * FROM student
                WHERE usn = %s"""
    params=(usn,)
    cur.execute(sql,params)
    oldStudent = cur.fetchone()
    if oldStudent == None:
        con.close()
        print("No student found")
        return
    
    print(f"""Name:{[oldStudent[0]]}
USN#:{oldStudent[1]}
Course:{oldStudent[2]}
Age:{oldStudent[3]}""")

    confirm = input("Are you sure to delete student(y/n)?")
    if confirm == "n":
        con.close()
        return 

    sql = """DELETE FROM student WHERE usn=%s"""
    params=(usn,)
    cur.execute(sql, params)
    con.commit()
    con.close()
    print("Student Deleted successfully!!!\n\n")


while True:
    menu_text = """1-Add Student
2-Edit Student
3-Delete Student
4-List All Students
0-Exit
Your choice:"""
    menu = int(input(menu_text))

    if 1==menu:
        AddStudent()
    elif 2==menu:
        EditStudent()
    elif 3==menu:
        DeleteStudent()
    elif 4==menu:
        ListAllStudents()
    else:   
        break