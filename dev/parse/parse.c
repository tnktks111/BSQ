//正常動作で0、それ以外は1を返す
int parse(char *file_path)
{
	char *str;
	str = file_read(file_path);
	if (validation(str))
		return (1);
	//文字列からintの配列の配列を生成
	//行ごとにヒストグラム生成
	//↑のヒストグラム処理
	//文字列を改変
	ft_putstr(str);
}