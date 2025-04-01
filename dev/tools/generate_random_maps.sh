mkdir -p ./maps  # mapsフォルダを作成（存在しなければ）
for i in {1..10}; do
    X=$((RANDOM % 21 + 10))  # 10〜30
    Y=$((RANDOM % 21 + 10))  # 10〜30
    D=$((RANDOM % 5 + 1))    # 1〜5
    perl ./tools/generate_map.pl "$X" "$Y" "$D" > "./maps/map_$i.txt"
    echo "map_$i.txt -> size: ${X}x${Y}, density: $D"
done
echo "✅ 10個のランダムマップを生成しました！"