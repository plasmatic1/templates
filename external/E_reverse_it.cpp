template<typename T> class reverse {
private:
    T& iterable_;
public:
    explicit reverse(T& iterable) : iterable_{iterable} {}
    auto begin() const { return std::rbegin(iterable_); }
    auto end() const { return std::rend(iterable_); }
};
template<typename T> class reverse_move {
private:
    T iterable_;
public:
    explicit reverse_move(T&& iterable) : iterable_{std::move(iterable)} {}
    auto begin() const { return std::rbegin(iterable_); }
    auto end() const { return std::rend(iterable_); }
};
