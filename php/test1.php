<?php
echo 'test1.php'."<br/>";
// 连接数据库
$link = mysqli_connect(
    'localhost',
    'root',
    'root',
    'mydb_one'
);
if (!$link){
    printf("数据库连接失败，Errorcode: %s",mysqli_connect_error());
    exit();
}
else
    echo "数据库连接成功"."<br/>";
//echo $link;
$result = mysqli_query($link,'SELECT * FROM phone_table');
echo $result;
// png