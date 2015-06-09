## Tenth Line

```bash
sed -n 10p file.txt
```

## Transpose File

```bash
awk '{for(i=1;i<=NF;i++) {if(s[i]=="") s[i]=$i; else s[i]=s[i]" "$i}} END {for(i=1;s[i]!="";i++) print s[i]; }' file.txt
```

## Valid Phone Numbers

```bash
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
```

## Word Frequency

```bash
tr -s ' ' '\n' < words.txt | sort | uniq -c | sort -nr | awk '{print $2" "$1}'
```
