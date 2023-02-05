import requests
import shutil

headers={"Content-Type": "application/x-www-form-urlencoded; charset=utf-8"}
print()
print("................:<<<<<:...Welcome to the Doorway to Hell ..:>>>>>>:..............".center(shutil.get_terminal_size().columns))
print("\n\n")
user = int(input("Enter Username: "))
data = {
    "password":user,
    "intrtype": 1,
    "prof": "Student",
    "username": user
}

response = requests.post("http://115.247.20.236//Student_Project/si_index.php", headers=headers, data=data)
user_id=response.json()["id"]
data1 = {
    
    "intrtype": 1,
    "prof": "Student",
    "id": user_id
}


response1 = requests.post("http://115.247.20.236/Student_Project/si_fetchsubject.php", headers=headers, data=data1)
response1=response1.json()
for i in response1:
    print( (i["name"] + "       "+ i["sub_id"]).center(shutil.get_terminal_size().columns) )


sub_id = int(input("Enter sub_id: "))
data5={
    "sub_id": sub_id
}



response2=requests.post("http://115.247.20.236/Student_Project/si_attendancetype.php",headers=headers,data=data5)
response2=response2.json()
atten_id=response2[0]["attendanceid"]
grp_id=response2[0]["groupid"]
data2={
    "grpid":grp_id,
    "attenid":atten_id,
    "sub_id":sub_id,
    "id":user_id
}



response3=requests.post("http://115.247.20.236/Student_Project/si_fetchsession.php",headers=headers,data=data2)
response3=response3.json()
print("Sessions you missed: ")
for j in response3:
    if j["status_id"]==0:
        print((j["ses_date"]+"          "+j["ses_id"]).center(shutil.get_terminal_size().columns))

print("Sessions u attended: ")
for j in response3:
    if j["status_id"]==1:
        print((j["ses_date"]+"          "+j["ses_id"]).center(shutil.get_terminal_size().columns))

print("Enter Ses id to mark attendance: ",end="")
ses_id=int(input())
data3={
    "student_id":user_id,
    "ses_id":ses_id,
}


response4=requests.post("http://115.247.20.236/Student_Project/si_attendanceupdate.php",headers=headers,data=data3)
if response3:
    print("Let's Go Babyy !!!!  ")
