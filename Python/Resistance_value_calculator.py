
#Resistance value calcuating by colors

res_col=['Black','Brown','Red','Orange','Yellow','Green','Blue','Violet','Grey','White','Gold','Silver']
sig_fig=list(range(0,10))

multipliers=[1,10,100,1000,10**4,10**5,10**6,10**7,10**8,10**9,0.1,0.01]


tolerance=['NA','1','2','0.05','0.02','0.5','0.25','0.1','0.01','NA','5','10']

print("---------- WELCOME TO RESISTANCE VALUE CALCULATOR ---------")

print("Valid colors : ")
print(res_col)
print()
print("Enter the colors of 4 bands in serial order . . . ")
band1color=(input("Enter Band 1 color: ").strip()).capitalize()
band2color=(input("Enter Band 2 color: ").strip()).capitalize()
band3color=(input("Enter Band 3(multiplier) color: ").strip()).capitalize()
band4color=(input("Enter Band 4(tolerance) color: ").strip()).capitalize()

inp_col=list((band1color,band2color,band3color,band4color))
print (inp_col)



if all(c in res_col for c in inp_col):
    NetValue=str(int(str(sig_fig[res_col.index(band1color)])+str(sig_fig[res_col.index(band2color)]))*(multipliers[res_col.index(band3color)]))+"  +-"+(tolerance[res_col.index(band4color)])+"%"

    print("Net value of given resistance : ",NetValue, "Ohms" )
else:
    print("Invalid color")




