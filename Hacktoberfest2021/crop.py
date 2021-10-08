import tkinter
import xlrd
import xlwt
import openpyxl as op
import matplotlib.pyplot as plt
def loginUser():
    window.destroy()
    window41 = tkinter.Tk()
    window41.geometry("400x200")
    window41.title("Crop Management System")
    tkinter.Label(window41,text = "WELCOME USER").pack()
    def vieway():
        window41.destroy()
        window51 = tkinter.Tk()
        window51.geometry("400x200")
        window51.title("Crop Management System")
        label51 = tkinter.Label(window51, text = "YEAR:")
        label51.place(x = 100 , y = 40)
        et31 = tkinter.Entry(window51, bd = 3)
        et31.place(x = 140, y = 40)
        def showy():
            h = int(et31.get())
            window51.destroy()
            loc = ("C:/Users/yasharth dubey/Downloads/CropsDataFile.xlsx")
            wb = xlrd.open_workbook(loc)
            sheet = wb.sheet_by_index(0)
            window61 = tkinter.Tk()
            window61.geometry("400x200")
            window61.title("Crop Management System")
            tkinter.Label(window61, text = "YOUR YEAR WISE DATA").pack()
            l111 = tkinter.Label(window61, text = "STATE NAME")
            l111.place(x = 5,y=20)
            l121 = tkinter.Label(window61, text = "DISTRICT NAME")
            l121.place(x = 265,y=20)
            l131 = tkinter.Label(window61, text = "CROP YEAR")
            l131.place(x = 545,y=20)
            l141 = tkinter.Label(window61, text = "SEASON")
            l141.place(x = 655,y=20)
            l151 = tkinter.Label(window61, text = "CROP")
            l151.place(x = 765,y=20)
            l161 = tkinter.Label(window61, text = "AREA")
            l161.place(x = 875,y=20)
            l171 = tkinter.Label(window61, text = "PRODUCTION")
            l171.place(x = 985,y=20)

            r = 40
            for i in range(0,sheet.nrows):
                if(sheet.cell_value(i,2)==h):
                    l1111 = tkinter.Label(window61, text = sheet.cell_value(i,0))
                    l1111.place(x = 0 , y = r)
                    l22 = tkinter.Label(window61, text = sheet.cell_value(i,1))
                    l22.place(x = 260 , y = r)
                    l33 = tkinter.Label(window61, text = str(int(sheet.cell_value(i,2))))
                    l33.place(x = 540, y = r)
                    l44 = tkinter.Label(window61, text = sheet.cell_value(i,3))
                    l44.place(x = 650, y = r)
                    l55 = tkinter.Label(window61, text = sheet.cell_value(i,4))
                    l55.place(x = 760, y = r)
                    l66 = tkinter.Label(window61, text = sheet.cell_value(i,5))
                    l66.place(x = 870 , y = r)
                    l77 = tkinter.Label(window61, text = sheet.cell_value(i,6))
                    l77.place(x = 980 , y = r)
                    r = r + 20
            window61.mainloop()
        bt61 = tkinter.Button(window51, text = "ENTER" , command = showy)
        bt61.place(x = 140 , y = 80)
    bt511 = tkinter.Button(window41,text = "VIEW BY YEAR",command = vieway)
    bt511.place(x = 150, y = 40)
    def viewac():
        window41.destroy()
        window8 = tkinter.Tk()
        window8.geometry("400x200")
        window8.title("Crop Management System")
        label81 = tkinter.Label(window8, text = "CROP:")
        label81.place(x = 100 , y = 40)
        et81 = tkinter.Entry(window8, bd = 3)
        et81.place(x = 140, y = 40)
        def showc():
            g = et81.get()
            window8.destroy()
            loc = ("C:/Users/yasharth dubey/Downloads/CropsDataFile.xlsx")
            wb = xlrd.open_workbook(loc)
            sheet = wb.sheet_by_index(0)
            a = [ ]
            b = [ ]
            c=[ ]
            d=[ ]
            for i in range(0,sheet.nrows):
                if(sheet.cell_value(i,4)==g):
                    a.append(sheet.cell_value(i,2))
                    b.append(sheet.cell_value(i,6))
            sum = 0
            for i in range(0,len(a)):
                h=0
                for k in c: 
                    if(k == a[i]) : 
                        h  = 1 
                if(h==0):
                    for j in range(0,len(a)):
                        if(a[i]==a[j]):
                            sum = sum + (b[j])
                    c.append((int)(a[i]))
                    d.append(sum)
                    sum=0            
            for i in range (len(c)):
                for j in range(i + 1, len(c)):
                    if(c[i] > c[j]):
                        temp = (int)(c[i])
                        c[i] = (int)(c[j])
                        c[j] = temp
                        temp = (int)(d[i])
                        d[i] = (int)(d[j])
                        d[j] = temp
            plt.xlabel("Year")
            plt.ylabel("Production")
            plt.bar(c,d)
            plt.show()
        bt82 = tkinter.Button(window8, text = "ENTER" , command = showc)
        bt82.place(x = 140 , y = 80)
    bt512 = tkinter.Button(window41,text = "VIEW BY CROP",command = viewac)
    bt512.place(x = 150,y=80)
    window41.mainloop()
def loginAdmin():
    window.destroy()
    window2 = tkinter.Tk()
    window2.title("Crop Management System")
    window2.geometry("400x200")
    label2 = tkinter.Label(window2,text = "LOGIN ID:")
    label2.place(x = 100,y = 40)
    et1 = tkinter.Entry(window2, bd = 3)
    et1.place(x = 160 , y = 40)
    def login():
        flag = 0
        loc = ("C:/Users/yasharth dubey/Downloads/LOGINID.xlsx")
        wb = xlrd.open_workbook(loc)
        sheet = wb.sheet_by_index(0)
        for i in range(0,sheet.nrows):
            if(sheet.cell_value(i,0)==et1.get()):
                flag = 1
                window2.destroy()
                window3 = tkinter.Tk()
                window3.title("Crop Management System")
                window3.geometry("400x200")
                label3 = tkinter.Label(window3,text = "PASSWORD:")
                label3.place(x = 90,y = 40)
                et2 = tkinter.Entry(window3, bd = 3, show = "*")
                et2.place(x = 160 , y = 40)
                def password():
                    flag1 = 0
                    for j in range(0,sheet.nrows):
                        if(sheet.cell_value(j,1)==int(et2.get())):
                            flag1 = 1
                    if(flag1 == 0):
                        tkinter.messagebox.showerror(title = "WRONG INPUT", message = "Program Terminating!")
                        window3.destroy()
                        exit()
                    if(flag1 == 1):
                        window3.destroy()
                        window4 = tkinter.Tk()
                        window4.geometry("400x200")
                        window4.title("Crop Management System")
                        tkinter.Label(window4,text = "WELCOME ADMIN").pack()
                        def vieway():
                            window4.destroy()
                            window5 = tkinter.Tk()
                            window5.geometry("400x200")
                            window5.title("Crop Management System")
                            label5 = tkinter.Label(window5, text = "YEAR:")
                            label5.place(x = 100 , y = 40)
                            et3 = tkinter.Entry(window5, bd = 3)
                            et3.place(x = 140, y = 40)
                           
                            def showy():
                                h = int(et3.get())
                                window5.destroy()
                                loc = ("C:/Users/yasharth dubey/Downloads/CropsDataFile.xlsx")
                                wb = xlrd.open_workbook(loc)
                                sheet = wb.sheet_by_index(0)
                                window6 = tkinter.Tk()
                                window6.geometry("400x200")
                                window6.title("Crop Management System")
                                tkinter.Label(window6, text = "YOUR YEAR WISE DATA").pack()
                                l11 = tkinter.Label(window6, text = "STATE NAME")
                                l11.place(x = 5,y=20)
                                l12 = tkinter.Label(window6, text = "DISTRICT NAME")
                                l12.place(x = 265,y=20)
                                l13 = tkinter.Label(window6, text = "CROP YEAR")
                                l13.place(x = 545,y=20)
                                l14 = tkinter.Label(window6, text = "SEASON")
                                l14.place(x = 655,y=20)
                                l15 = tkinter.Label(window6, text = "CROP")
                                l15.place(x = 765,y=20)
                                l16 = tkinter.Label(window6, text = "AREA")
                                l16.place(x = 875,y=20)
                                l17 = tkinter.Label(window6, text = "PRODUCTION")
                                l17.place(x = 985,y=20)

                                r = 40
                                for i in range(0,sheet.nrows):
                                    if(sheet.cell_value(i,2)==h):
                                      l1 = tkinter.Label(window6, text = sheet.cell_value(i,0))
                                      l1.place(x = 0 , y = r)
                                      l2 = tkinter.Label(window6, text = sheet.cell_value(i,1))
                                      l2.place(x = 260 , y = r)
                                      l3 = tkinter.Label(window6, text = str(int(sheet.cell_value(i,2))))
                                      l3.place(x = 540, y = r)
                                      l4 = tkinter.Label(window6, text = sheet.cell_value(i,3))
                                      l4.place(x = 650, y = r)
                                      l5 = tkinter.Label(window6, text = sheet.cell_value(i,4))
                                      l5.place(x = 760, y = r)
                                      l6 = tkinter.Label(window6, text = sheet.cell_value(i,5))
                                      l6.place(x = 870 , y = r)
                                      l7 = tkinter.Label(window6, text = sheet.cell_value(i,6))
                                      l7.place(x = 980 , y = r)
                                      r = r + 20
                                window6.mainloop()
                            bt6 = tkinter.Button(window5, text = "ENTER" , command = showy)
                            bt6.place(x = 140 , y = 80)
                        def viewac():
                            window4.destroy()
                            window81 = tkinter.Tk()
                            window81.geometry("400x200")
                            window81.title("Crop Management System")
                            label811 = tkinter.Label(window81, text = "CROP:")
                            label811.place(x = 100 , y = 40)
                            et811 = tkinter.Entry(window81, bd = 3)
                            et811.place(x = 140, y = 40)
                            def showc():
                                g = et811.get()
                                window81.destroy()
                                loc = ("C:/Users/yasharth dubey/Downloads/CropsDataFile.xlsx")
                                wb = xlrd.open_workbook(loc)
                                sheet = wb.sheet_by_index(0)
                                a = [ ]
                                b = [ ]
                                c=[ ]
                                d=[ ]
                                for i in range(0,sheet.nrows):
                                    if(sheet.cell_value(i,4)==g):
                                        a.append(sheet.cell_value(i,2))
                                        b.append(sheet.cell_value(i,6))
                                sum = 0
                                for i in range(0,len(a)):
                                    h=0
                                    for k in c: 
                                        if(k == a[i]) : 
                                            h  = 1 
                                    if(h==0):
                                        for j in range(0,len(a)):
                                            if(a[i]==a[j]):
                                                sum = sum + (b[j])
                                        c.append((int)(a[i]))
                                        d.append(sum)
                                        sum=0            
                                for i in range (len(c)):
                                    for j in range(i + 1, len(c)):
                                        if(c[i] > c[j]):
                                            temp = (int)(c[i])
                                            c[i] = (int)(c[j])
                                            c[j] = temp
                                            temp = (int)(d[i])
                                            d[i] = (int)(d[j])
                                            d[j] = temp
                                plt.xlabel("Year")
                                plt.ylabel("Production")
                                plt.bar(c,d)
                                plt.show()
                            bt7 = tkinter.Button(window81,text = "ENTER",command = showc)
                            bt7.place(x = 140 , y = 80)
                        bt5 = tkinter.Button(window4,text = "VIEW BY YEAR",command = vieway)
                        bt5.place(x = 150, y = 40)
                        bt6 = tkinter.Button(window4,text = "VIEW BY CROP",command = viewac)
                        bt6.place(x = 150, y = 80)
                        def addData():
                            window4.destroy()
                            window10 = tkinter.Tk()
                            window10.geometry("450x300")
                            window10.title("Crop Management System")
                            tkinter.Label(window10,text = "PLEASE PROVIDE THE FIELDS").pack()
                            q1 = tkinter.Label(window10,text = "STATE NAME:")
                            q1.place(x = 40, y = 20)
                            q2 = tkinter.Label(window10,text = "DISTRICT NAME:")
                            q2.place(x = 40, y = 50)
                            q3 = tkinter.Label(window10,text = "CROP YEAR:")
                            q3.place(x = 40, y = 80)
                            q4 = tkinter.Label(window10,text = "SEASON:")
                            q4.place(x = 40, y = 110)
                            q5 = tkinter.Label(window10,text = "CROP:")
                            q5.place(x = 40, y = 140)
                            q6 = tkinter.Label(window10,text = "AREA:")
                            q6.place(x = 40, y = 170)
                            q7 = tkinter.Label(window10,text = "PRODUCTION:")
                            q7.place(x = 40, y = 200)
                            w1 = tkinter.Entry(window10,bd = 3,width = 40)
                            w1.place(x= 150 , y = 20)
                            w2 = tkinter.Entry(window10,bd = 3,width = 40)
                            w2.place(x= 150 , y = 50)
                            w3 = tkinter.Entry(window10,bd = 3,width = 40)
                            w3.place(x= 150 , y = 80)
                            w4 = tkinter.Entry(window10,bd = 3,width = 40)
                            w4.place(x= 150 , y = 110)
                            w5 = tkinter.Entry(window10,bd = 3,width = 40)
                            w5.place(x= 150 , y = 140)
                            w6 = tkinter.Entry(window10,bd = 3,width = 40)
                            w6.place(x= 150 , y = 170)
                            w7 = tkinter.Entry(window10,bd = 3,width = 40)
                            w7.place(x= 150 , y = 200)
                            def write():
                                z1 = w1.get()
                                z2 = w2.get()
                                z3 = w3.get()
                                z4 = w4.get()
                                z5 = w5.get()
                                z6 = w6.get()
                                z7 = w7.get()
                                if (z1 == "") or (z2 == "") or (z3 == "") or (z4 == "") or (z5 == "") or (z6 == "") or (z7 == ""):
                                    tkinter.messagebox.showinfo(title="EMPTY SPACE",message="Please Fill the Details")
                                else:
                                    wb = op.load_workbook("C:/Users/yasharth dubey/Downloads/CropsDataFile.xlsx")
                                    ws = wb.get_sheet_by_name("Sheet1")
                                    ws.append([z1,z2,int(z3),z4,z5,float(z6),float(z7)])
                                    wb.save(filename = 'C:/Users/yasharth dubey/Downloads/CropsDataFile.xlsx')
                                    wb.close()
                                    tkinter.messagebox.showinfo(title = "FILE SAVED", message = "Your Data is saved")
                                    window10.destroy()
                                    tkinter.messagebox.showinfo(title="THANKS",message="THANKS FOR USING OUR GUI")

                            bt90 = tkinter.Button(window10,text = "ENTER",command = write)
                            bt90.place(x = 200,y = 240 )
                        bt10 = tkinter.Button(window4,text = "ADD DATA",command = addData)
                        bt10.place(x = 155, y = 120)
                        window4.mainloop()
                bt3 = tkinter.Button(window3, text = "ENTER",command = password)
                bt3.place(x = 160, y = 80)
                window3.mainloop()
        if flag == 0:
            tkinter.messagebox.showerror(title = "WRONG INPUT", message = "Program Terminating!")
            window2.destroy()
            exit()
    bt2 = tkinter.Button(window2, text = "LOGIN",command = login)
    bt2.place(x = 160, y = 80)
window = tkinter.Tk()
window.title("Crop Management System")
window.geometry("400x200")
tkinter.Label(window,text = "WELCOME TO CROP MANAGEMENT SYSTEM").pack()
bt = tkinter.Button(window, text = "LOGIN AS ADMIN", command = loginAdmin)
bt.place(x = 160 , y = 40)
bt1 = tkinter.Button(window,text = "LOGIN AS USER", command = loginUser)
bt1.place(x = 165 , y = 80)
bt4 = tkinter.Button(window,text = "EXIT", command = exit )
bt4.place(x = 190 , y = 120)
window.mainloop()