package chuchu.miniproject.domain.worker;

import chuchu.miniproject.domain.Role;
import chuchu.miniproject.domain.Team;
import jakarta.persistence.*;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.time.LocalDate;

@NoArgsConstructor
@Getter
@Setter
@Entity
public class Worker {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false, length = 25)
    private String name;


    @Column(length = 25)
    private String teamName;

    @Enumerated(EnumType.STRING)
    @Column(nullable = false)
    private Role role;

    @Column(nullable = false)
    private LocalDate birthday;

    @Column(nullable = false)
    private LocalDate workStartDate;

    @ManyToOne
    @JoinColumn(name = "team_id")
    private Team team;

    @Builder
    public Worker(String name, String teamName, Role role, LocalDate birthday, LocalDate workStartDate, Team team) {
        this.name = name;
        this.teamName = teamName;
        this.role = role;
        this.birthday = birthday;
        this.workStartDate = workStartDate;
        this.team = team;
    }
}
