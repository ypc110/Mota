package User;
import operation.*;
import java.util.Scanner;
/**
 * user：ypc；
 * date：2021-04-22;
 * time: 16:41;
 */
public class NormalUser extends User{
    public NormalUser(String name) {
        super(name);

        this.operations= new IOperation[] {
                new ExitOperation(),
                new FindOperation(),
                new BorrowOperation(),
                new ReturnOperation()
        };
    }
    @Override
    public int menu() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("==========="+ "hello " + this.name +" 欢迎！==============");
        System.out.println("1.查找图书");
        System.out.println("2.借阅图书");
        System.out.println("3.归还图书");
        System.out.println("0.退出系统");
        System.out.println("=====================================================");
        int choice = scanner.nextInt();
        return choice;
    }
}



