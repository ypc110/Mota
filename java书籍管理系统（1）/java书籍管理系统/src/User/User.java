package User;
import operation.IOperation;
import book.*;
/**
 * user：ypc；
 * date：2021-04-22;
 * time: 16:33;
 */
public abstract class User {
    protected String name;
    protected  IOperation[] operations;
    public User(String name) {
        this.name = name;
    }
    // 显示菜单
     abstract public int menu();
    // 根据用户选项执行操作
     public void doOperation(int choice, BookList bookList) {
         operations[choice].work(bookList);
     }
}
