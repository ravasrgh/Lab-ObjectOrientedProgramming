public class Checkout {
    private PaymentStrategy paymentStrategy;

    public Checkout() {
        this.paymentStrategy = null;
    }

    public void setPaymentStrategy(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }
    public void processPayment(int amount) {
        if (this.paymentStrategy == null) {
            System.out.println("No payment method selected");
        }
        else{
            this.paymentStrategy.pay(amount);
        }
    }

}