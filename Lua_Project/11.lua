

--require "luasql.sqlserver"
testdb.sql init sqlserver

testmssql.lua test for luasqlserver lib

--������������
env = luasql.mysql()

--�������ݿ�
conn = env:connect("MyDataBase","sa","88888888","127.0.0.1",1433)

--�������ݿ�ı����ʽ
conn:execute"SET NAMES UTF8"

--ִ�����ݿ����
cur = conn:execute("select * from role")

row = cur:fetch({},"a")

--�ļ�����Ĵ���
file = io.open("role.txt","w+");

while row do
    var = string.format("%d %s\n", row.id, row.name)

    print(var)

    file:write(var)

    row = cur:fetch(row,"a")
end


file:close()  --�ر��ļ�����
conn:close()  --�ر����ݿ�����
env:close()   --�ر����ݿ⻷��
