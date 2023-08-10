import pymysql 
class App:
    def Db(self):
        con=pymysql.connect(host='localhost',
            port=3306,
            database='epms_app',
            user='root',password='')
        return con
    def CreateAction(self):
        con = self.Db()
        code = input("Enter code:")
        name = input("Enter name:")
        joining_date = input("Enter joining date(yyyy-mm-dd):")
        job_title = input("Enter job title:")
        sql = """INSERT INTO EMPLOYEE 
            (code,name,joining_date, job_title)
            values 
            (%s, %s,%s,%s) """
        params = (code,name,joining_date, job_title)    
        cur = con.cursor()
        cur.execute(sql, params)
        con.commit()
        con.close()
        print("Employee Created Successfully")
    def ListAllAction(self):
        con = self.Db()
        cur = con.cursor()
        sql = """SELECT * FROM employee"""
        params = ()
        cur.execute(sql, params)
        employees = cur.fetchall()
        con.close()
        print("#\tCode\tName\tJoining Date\tJob Title\tSalary")
        for e in employees:
            print(f"{e[0]}\t{e[1]}\t{e[2]}\t{e[3]}\t{e[4]}\t{e[5]}")
        

    def UpdateSalaryAction(self):
        code = input("Enter code:")
        con = self.Db()
        cur = con.cursor()
        sql = """SELECT * FROM employee 
                WHERE code = %s"""
        params = (code, )
        cur.execute(sql, params)
        employee = cur.fetchone()
        if employee == None:
            con.close()
            return 
        print(f"""Employee Name: {employee[2]}
Code: {employee[1]}
Salary: {employee[5]}""")
        salary = float(input("New Salary:"))
        sql = """UPDATE employee 
        SET salary=%s
        WHERE code=%s"""
        params = (salary, code)
        cur.execute(sql,params)
        con.commit()
        con.close()
        print("Employee salary updated successfully")

    def DeleteAction(self):
        code = input("Enter code:")
        con = self.Db()
        cur = con.cursor()
        sql = """SELECT * FROM employee 
                WHERE code = %s"""
        params = (code, )
        cur.execute(sql, params)
        employee = cur.fetchone()
        if employee == None:
            con.close()
            return 
        print(f"""Employee Name: {employee[2]}
Code: {employee[1]}
Salary: {employee[5]}""")
        confirm = input("Are you sure to delete(y/n)?")
        if confirm == "n":
            con.close()
            return 
        sql = """DELETE FROM employee
        WHERE code=%s"""
        params = (code, )
        cur.execute(sql,params)
        con.commit()
        con.close()
        print("Employee deleted successfully")
         

#--Driver Code - Menu Driven
app = App()
#app.CreateAction()
#app.UpdateSalaryAction()
#app.DeleteAction()
app.ListAllAction()