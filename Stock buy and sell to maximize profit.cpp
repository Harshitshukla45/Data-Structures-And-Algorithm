private static int calculateProfit(int[] arr) {

Integer buy = null;
Integer profit = 0;
for (int i = 0; i < arr.length ; i++) {
if (buy == null) {
buy = arr[i];
System.out.println("buy price : " + arr[i]);
}

if (arr[i] > buy && ( (i == arr.length - 1) || (arr[i + 1] < buy))) {
profit = (arr[i] - buy) + profit;
System.out.println("sell price : " + arr[i]);
buy = null;
}
}
return profit;
}
