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
if ($result){
    echo '$result is ok</br>';
    while ( $row = mysqli_fetch_assoc($result) ) {
        echo $row['name'], "&nbsp;", "</br>";
    }
}
mysqli_free_result($result);

mysqli_close($link);
// png


