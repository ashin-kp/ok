<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>Login page</h2>
    <form method="POST">
        <table>
            <tr>
                <th>username:</th>
                <td> <input type="text" name="username"></td>
            </tr>
            <tr>
                <th>password:</th>
                <td> <input type="password" name="password" id=""></td>
            </tr>
            <tr>
                <button name="login" type="submit">Login</button>
                <input type="reset" value="reset">
            </tr>
        </table>
    </form>
    <?php 
    if(isset($_POST['login'])){
        $con = mysqli_connect("localhost","root","","studentManagement");
        if(!$con)
            echo "connection error";
        $username = $_POST['username'];
        $password = $_POST['password'];
        $sq = "SELECT * FROM login WHERE username='$username' AND password='$password'";
        $res = mysqli_query($con , $sq);
        if(mysqli_num_rows($res)>0){
            echo "<script>alert('Login successful!');</script>";
            header("Location: admin.php");
            exit();
        }

        else
            echo "<script>alert('login unsuccessful');</script>";
    }?>

</body>
</html>