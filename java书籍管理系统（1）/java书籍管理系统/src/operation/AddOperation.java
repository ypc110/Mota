package operation;
import book.Book;
import book.BookList;
import java.util.Scanner;
/**
 * user：ypc；
 * date：2021-04-22;
 * time: 15:49;
 */
public class AddOperation implements IOperation {
    @Override
    public void work(BookList booklist) {
        Scanner s = new Scanner(System.in);
        String name = null;
        String author = null;
        int price = 0;
        String type = null;
        boolean isBorrowed = false;
        Book book = new Book(name,author,price,type,isBorrowed);
        System.out.println("请输入书名");
        book.setName(s.nextLine());
        System.out.println("请输入作者");
        book.setAuthor(s.nextLine());
        System.out.println("请输入价格");
        book.setPrice(s.nextInt());
        System.out.println("请输入类型");
        book.setType(s.nextLine());
        booklist.setBook(booklist.getSize(),book);
        booklist.setSize(booklist.getSize()+1);
        System.out.println("增加书籍成功");
    }
}
