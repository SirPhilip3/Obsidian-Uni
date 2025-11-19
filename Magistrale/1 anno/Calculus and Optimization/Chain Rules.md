---
publish: true
---
Given $f: \mathbb{R}^n \to \mathbb{R}^m$, with $f \in C^1(\mathbb{R}^n)$ , then we say that the *matrix* : 
$$
\nabla f(x) = \bigg[ \nabla f_i(x)\ \vdots \ \dots \ \vdots\ \nabla f_m(x) \bigg] \in \mathbb{R}^{n \times m}
$$
called the **gradient matrix** associated to $f(x)$ 

Also the **Jabobian** of $f(x)$ is :
$$
J(x) = [\nabla f(x)]^T \in \mathbb{R}^{m \times n}
$$

>[!note] 
>The *Hessian* matrix $\nabla^2 f(x) = J[\nabla f(x)]$ 

# Chain Rule 1 

Let $f: \mathbb{R}^n \to \mathbb{R}^m$ and $g: \mathbb{R}^m \to \mathbb{R}^l$  and the *composite* function $h : $f: \mathbb{R}^n \to \mathbb{R}^l$ such that : 
$$
h(x) = g[f(x)]
$$
Than we have that : 
$$
\nabla h(x) = \nabla f(x)\nabla g[f(x)] \in \mathbb{R}^{n \times l}
$$

>[!example] 
>#todo

# Chain Rule 2 

Let's now consider $n$ functions $x_i : \mathbb{R} \to \mathbb{R}, \ i=1, \dots, n$ with $x_i(t) \in C^1 (\mathbb{R})$ for any $t \in \mathcal{S}$ 
Now given the function $f : \mathbb{R}^n \to \mathbb{R}$ with $f \in C^1(\mathbb{R}^n)$ being : 
$$
F(t) = f[x_1(t),x_2(t), \dots, x_n(t)]
$$ We have that its *derivative* will be : 
$$
\frac{\partial F(t)}{\partial} \equiv \frac{dF(t)}{dt} \equiv F'(t) = \frac{\partial f(x)}{\partial x_1} \cdot x_1'(t) + \dots + \frac{\partial f(x)}{\partial x_n} \cdot x_n'(t) 
$$

>[!note] 
>In control systems we may have the following : $\tilde{F}(t) = \tilde{f}[x_1(t),x_2(t), \dots, x_n(t),t]$ , or $\tilde{F}(t)$ explicitly depends on the *time* $t$
>
>Than we can write using the previous rule : 
>$$
>\frac{d\tilde{F}(t)}{dt} = F'(t) + \frac{\partial \tilde{f}(t)}{\partial t} \cdot 1
>$$

>[!example] 
>#todo


