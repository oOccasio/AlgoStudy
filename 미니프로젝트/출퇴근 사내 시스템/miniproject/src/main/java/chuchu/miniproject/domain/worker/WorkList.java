package chuchu.miniproject.domain.worker;

import jakarta.persistence.*;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

@NoArgsConstructor
@Entity
@Getter
public class WorkList {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;


    @Column(nullable = false)
    private LocalDate workDate;

    @Column(nullable = false)
    private Integer workingMinutes;

    @Column(nullable = false)
    private boolean work;

    @ManyToOne
    @JoinColumn(name = "worker_id")
    private Worker worker;


    @Builder
    public WorkList(LocalDate workDate, Integer workingMinutes, boolean work, Worker worker) {
        this.workDate = workDate;
        this.workingMinutes = workingMinutes;
        this.work = work;
        this.worker = worker;
    }

    public void isNotWorking() {
        this.work = false;
    }
}
