package operation;
import book.BookList;
/**
 * user：ypc；
 * date：2021-04-22;
 * time: 15:50;
 */
public class DisplayOperation implements IOperation{
    @Override
    public void work(BookList booklist) {
        System.out.println("显示图书！！！");
        for (int i = 0; i <booklist.getSize(); i++) {
            System.out.println(booklist.getBook(i));
        }
    }
}
