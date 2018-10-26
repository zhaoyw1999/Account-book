# 个人账本开发文档

## 需求分析

    ### 总述
    
        该系统要求实现一一个简单、实用的个人帐本管理程序。
        主要功能包括帐务收支明细数据的录入、查找、修改、删除、统计、排序等。
        
        个人帐务数据是由帐务明细条目构成，其信息应包括
            - 序号
            - 日期(年、月、日)
            - 收支项名称
            - 收支类型（收入、支出）
            - 收支金额（正/负数表示收支）
            - 备注
    
    ### 功能要求
        
        - 有明确的多级菜单选择功能
        - 能够随时添加帐务明细数据
        - 查找帐务数据
            + 可按序号、日期（年、月、日）、名称、金额等查找
        - 修改帐务明细条目
        - 删除帐务明细条目
        - 对帐务数据排序
            + 可按日期、名称、金额等排序
            + 排序后，记录的序号也要重新编排
        - 显示当前所有帐务数据列表
        - 帐务统计
            + 根据日期范围，可分别按年、月或日统计收、支、结余总金额，并显示
        - 保存帐务数据到文件中、从文件中读入帐务数据
        - 增加预算管理、对超出预算的分类予以提醒
    

## 模块设计

    ### Models - 曹家琪 （Q17010125）

    - Item: struct
        - id_: int
        - date_: string(YYYY-MM-DD)
        - name_: string
        - type_: int
            + INCOME -> 1
            + EXPENSE -> 0
        - amount_: int
        - remark_: string
        - Item(cId: int, cDate: string, cName: string, cType: int, cAmount:int, cRemark: string): constructor
        - ~Item(): finalizer
        - operator < (it_1: const Item &, it_2: const Item &): bool

    - compareById(it_1: const Item &, it_2: const Item &): bool
    - compareByDate(it_1: const Item &, it_2: const Item &): bool
    - compareByAmount(it_1: const Item &, it_2: const Item &): bool


    ### Controller - 赵玉炜 （Q17010123）
    - DataSet: class
    - private
        - dataContainner_: set <Item>
    - public
        - DateSet(): constructor
        - ~DateSet(): finalizer
        - idAllocator(): int
        - getAllData(): set <Item>
        - getDataById(id: int): Item
        - getDataByDate(minDate: string, maxDate: string): set <Item>
        - getDataByName(name: string): set <Item>
        - getDataByType(type: int): set <Item>
        - getDataByAmount(minAmount: int, maxAmount: int): set <Item>
        - setDateById(id: int, date: string): bool
        - setNameById(id: int, name: string): bool
        - setTypeById(id: int, type: int): bool
        - setAmountById(id: int, amount: int): bool
        - setRemarkById(id: int, remark: string) bool
        - addItem(item: Item): bool
        - deleteItem(id: int): bool
        - readData(): bool
        - saveData(): bool
        - sumByDate(minDate: string, maxDate: string): int


    ### Views - 季慧山 （Q17010122）

    - Views: class
    - private
        - showMenu(): void
        - showTipsOfAdd(): void
        - showTipsOfSearch(): void
        - showTipsOfUpdate(): void
        - showTipsOfDelete(): void
        - showTipsOfDisplay(): void
        - showTipsOfDatesCalculateModels(minDate: string, maxDate: string): void
        - showSaveDone(): void
    - public
        - showWelcome(): static void
        - watch(): void
        - showTips(tipId: int): void

## 开发规范

    - 命名：按照模块设计中的方法
        - 类名首字母大写，每个单词的首字母大写
        - 属性名首字母小写，每个单词的首字母大写，所有属性末尾加下划线
        - 方法名/函数名首字母小写，每个单词的首字母大写
    - Tab: SoftTab
    - 空格
        - 标点符号后加空格
        - 运算符两边有空格
        - for/while空格()
        - function没有空格()
    - 大括号
        - ()空格{
            // TO DO
            }
