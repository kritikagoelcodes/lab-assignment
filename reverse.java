public class reverse {
    public static void rev(int numbers[]){
        int first = 0;
        int last = numbers.length-1;
        while(first<last){
            int temp = numbers[first];
            numbers[first] = numbers[last];
            numbers[last] = temp;
            first ++;
            last --;
        }
    }
    public static void main(String args[]){
        int numbers[] = {1,3,5,8,10};
        rev(numbers);
        for(int i = 0; i<numbers.length;i++){
             System.out.print(numbers[i] + " ");
        }
        
    }
}
