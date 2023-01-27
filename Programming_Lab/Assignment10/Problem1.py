import tkinter as tk


# constants and lists
allStates = ["Maharashtra", "Karnataka", "Madhya Pradesh", "Uttar Pradesh", "Jammu & Kashmir"]
HEIGHT = 1
WIDTH = 50

# Declare and initialize window
window = tk.Tk()
window.title("Student Registration System")
window.geometry("502x700")

# Declare frames for input, message
frame1 = tk.Frame(window)
frame2 = tk.Frame(window)
frame1.pack()
frame2.pack()

# Declare and initialize labels
nameLabel = tk.Label(frame1, text = "Name")
addressLabel = tk.Label(frame1, text = "Address")
mobileLabel = tk.Label(frame1, text = "Mobile Number")
emailLabel = tk.Label(frame1, text = "Email ID")
nameText = tk.Text(frame1, height = HEIGHT, width = WIDTH)
addressText = tk.Text(frame1, height  = 3 * HEIGHT, width = WIDTH)
mobileText = tk.Text(frame1, height = HEIGHT, width = WIDTH)
emailText = tk.Text(frame1, height = HEIGHT, width = WIDTH)

for field in [nameLabel, nameText, addressLabel, addressText, mobileLabel, mobileText, emailLabel, emailText]:
    field.pack()


# Create radio button for gender field
gender = tk.IntVar()
isMale = tk.Radiobutton(frame2, text = 'Male', value = 1, variable = gender)
isFemale = tk.Radiobutton(frame2, text = 'Female', value = 2, variable = gender)
isMale.pack()
isFemale.pack()


# Create listbox for state field
states = tk.Listbox(frame2, height = len(allStates), width = WIDTH)
for i in range(len(allStates)):
    states.insert(i, allStates[i])

states.pack()

# Create Checkbox for hostel requirement
isHostel = tk.IntVar()
isHostelReq = tk.Checkbutton(frame2, text = "Do you want to opt for college hostel ?", variable=isHostel)
isHostelReq.pack()

# Display all the details on console and in MessageBox

def submit():
    window.option_clear()
    name = nameText.get('1.0', 'end')
    address = addressText.get('1.0', 'end')
    mobile = mobileText.get('1.0', 'end')
    email = emailText.get('1.0', 'end')
    message = "The Data received is as follows :\n"
    message += f'Name : {name} \nEmail : {email} \nAddress : {address} \nMobile Number : {mobile}'
    if gender.get() == 1:
        message += f'Gender : Male\n'
    elif gender.get() == 2:
        message += f'Gender : Female\n'
    else:
        message += f'Gender : Not Specified\n'
    state = ""
    for i in states.curselection():
        state += allStates[i]
    message += f'State : {state}\n'
    message += "Hostel : "
    if isHostel.get() == 1:
        message += "Yes\n"
    else:
        message += "No\n"
    messageBox = tk.Message(window,text =  message)
    messageBox.config(bg = 'lightgreen')
    messageBox.place(relx = 0.5, rely = .8, anchor = tk.CENTER)

submitButton = tk.Button(window, text = "Submit", command = submit)
submitButton.pack()
window.mainloop()
