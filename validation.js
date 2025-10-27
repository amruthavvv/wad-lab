<!DOCTYPE html>
<html>
<head>
    <title>Registration Form</title>
    <style>
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: lightgray;
            font-family: Arial, sans-serif;
        }
        form {
            padding: 30px;
            border-radius: 10px;
            width: 300px;
            background-color: white;
            box-shadow: 0 4px 8px rgba(0,0,0,0.1);
        }
        label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
        }
        input[type="text"], 
        input[type="email"], 
        input[type="password"] {
            width: 93%;
            padding: 10px;
            margin-bottom: 15px;
            border: 1px solid gray;
            border-radius: 5px;
        }
        input[type="submit"] {
            width: 100%;
            padding: 10px;
            background-color: green;
            color: white;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            font-size: 16px;
        }
        input[type="submit"]:hover {
            background-color: darkgreen;
        }
    </style>
</head>
<body>

<form onsubmit="return validate()">

    <label for="user">User Name</label>
    <input type="text" id="user" name="username">

    <label for="email">Email</label>
    <input type="email" id="email" name="email">

    <label for="pass">Password</label>
    <input type="password" id="pass" name="password">

    <label for="cpass">Confirm Password</label>
    <input type="password" id="cpass" name="confirmpassword">

    <input type="submit" value="Submit">

</form>

<script>
    function validate() {
        var user = document.getElementById("user").value;
        var email = document.getElementById("email").value;
        var pass = document.getElementById("pass").value;
        var cpass = document.getElementById("cpass").value;

        if (user === "" || email === "" || pass === "" || cpass === "") {
            alert("Please fill out all fields!");
            return false;
        }

        if (pass !== cpass) {
            alert("Password and Confirm Password must match!");
            return false;
        }

        alert("Form submitted successfully!");
        return true;
    }
</script>

</body>
</html>
