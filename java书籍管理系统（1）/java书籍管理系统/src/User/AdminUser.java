package User;
import operation.*;
import java.util.Scanner;

/**
 * user：ypc；
 * date：2021-04-22;
 * time: 16:57;
 */
public class AdminUser extends User {
    public AdminUser(String name) {
        super(name);
        //2、准备操作对象
        this.operations = new IOperation[]{
                new ExitOperation(),
                new FindOperation(),
                new AddOperation(),
                new DelOperation(),
                new DisplayOperation()
        };
    }

    @Override
    public int menu() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("===========" + "hello " + this.name + " 欢迎！==============");
        System.out.println("1.查找图书");
        System.out.println("2.新增图书");
        System.out.println("3.删除图书");
        System.out.println("4.显示图书");
        System.out.println("0.退出系统");
        System.out.println("=====================================================");
        int choice = scanner.nextInt();
        return choice;
    }
}
