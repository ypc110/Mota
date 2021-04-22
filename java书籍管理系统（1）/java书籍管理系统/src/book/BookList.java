package book;

import java.util.Arrays;

/**
 * user：ypc；
 * date：2021-04-22;
 * time: 15:41;
 */
public class BookList {
    @Override
    public String toString() {
        return "BookList{" +
                "books=" + Arrays.toString(books) +
                ", useSize=" + useSize +
                '}';
    }
    private Book [] books = new Book[10];
    private int useSize = 3;
    public BookList() {
        books[0] = new Book("三国演义", "罗贯中", 100, "小说",false);
        books[1] = new Book("水浒传", "施耐庵", 100, "小说",false);
        books[2] = new Book("西游记", "吴承恩", 100, "小说",false);
    }
    public Book getBook(int pos) {
       return books[pos];
    }
    public void setBook(int pos, Book book) {
       books[pos] = book;
    }
    public int getSize() {
       return useSize;
       }
    public void setSize(int size) {
       this.useSize = size;
    }
}