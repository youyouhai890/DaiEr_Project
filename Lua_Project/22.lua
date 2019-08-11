

-- coroutine_test.lua �ļ�
co = coroutine.create(		--����Эͬ���򣬷���Эͬ���� ������һ������������resume���ʹ�õ�ʱ��ͻ��Ѻ�������
    function(i)
        print(i);
    end
)

--����Эͬ���򣬺�create���ʹ��	,	Ӧ�ò���
coroutine.resume(co, 111)   -- 1
--�鿴Эͬ�����״̬
print(coroutine.status(co))  -- dead
print("----------------------------------------------------------------------------")

--����Эͬ���򣬷���һ��������һ�����������������ͽ���Эͬ���򣬺�create�����ظ�
co = coroutine.wrap(
    function(i)
        print(i);
    end
)

co(222)	--����Э�ɷ���	,	Ӧ�ò���

print("================================================================================")

co2 = coroutine.create(
    function()
        for i=1,10 do
            print(i)
            if i == 3 then
                print(coroutine.status(co2))  --running
                print(coroutine.running()) --thread:XXXXXX
            end
            coroutine.yield()
        end
    end
)

coroutine.resume(co2) --1
coroutine.resume(co2) --2
coroutine.resume(co2) --3

print(coroutine.status(co2))   -- suspended
print(coroutine.running())

print("----------")
